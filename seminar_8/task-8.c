/*
 *  ___  ____    _   _  ___ _____ _____ ____
 * / _ \/ ___|  | \ | |/ _ \_   _| ____/ ___|
 *| | | \___ \  |  \| | | | || | |  _| \___ \
 *| |_| |___) | | |\  | |_| || | | |___ ___) |
 * \___/|____/  |_| \_|\___/ |_| |_____|____/
 *
 * Created on 2023-10-18 by Grindelf P.
 *
 * Semaphore operations.
 */

#include <sys/shm.h>
#include <sys/sem.h>
#include <printf.h>
#include <unistd.h>
#include <signal.h>
#include "../headers/commons.hpp"

#define SHM_KEY 14741
#define SEM_KEY 14713
#define SEM_KEY_2 14715
#define SEM_SIZE 1
#define OP_SIZE 1
#define SIZE 128
#define SHM_I_SIZE (SIZE / sizeof(int))
#define INCREMENT 1
#define DECREMENT (-1)

void lowerSemaphore(int semaphore) {
    struct sembuf operation;

    operation.sem_num = 0;
    operation.sem_op = DECREMENT;
    operation.sem_flg = 0;

    semop(semaphore, &operation, OP_SIZE);
}

void raiseSemaphore(int semaphore) {
    struct sembuf operation;

    operation.sem_num = 0;
    operation.sem_op = INCREMENT;
    operation.sem_flg = 0;

    semop(semaphore, &operation, OP_SIZE);
}

int main() {
    int sharedMemory = shmget(SHM_KEY, SIZE, IPC_CREAT | 0666); // shared memory descriptor
    if (sharedMemory < 0) return ERROR;

    int *a = (int *) shmat(sharedMemory, NULL, 0); // shared memory pointer NULL - recommended location
    if (a == NULL) return ERROR;

    a[0] = 0;
    int counter = 0;
    int childPid;
    int childSemaphore = semget(SEM_KEY, SEM_SIZE, IPC_CREAT | 0666);
    semctl(childSemaphore, 0, SETVAL, 1); // child semaphore is unlocked (starts with 1 value)
    int parentSemaphore = semget(SEM_KEY_2, SEM_SIZE, IPC_CREAT | 0666);
    semctl(parentSemaphore, 0, SETVAL, 0); // parent semaphore is locked (starts with 0 value)

    if (!fork()) {
        childPid = getpid();
        while (a[0] < SHM_I_SIZE) {
            lowerSemaphore(childSemaphore);
            if (a[0] % 2 == 0) {
                int k = ++a[0];
                a[k] = 1;
                raiseSemaphore(parentSemaphore);
            }
            counter++;
        }
        printf("Child counter: %d\n", counter);

    } else {
        while (a[0] < SHM_I_SIZE) {
            lowerSemaphore(parentSemaphore);
            if (a[0] % 2 == 1) {
                int k = ++a[0];
                a[k] = 2;
                raiseSemaphore(childSemaphore);
            }
            counter++;
        }
        printf("Parent counter: %d\n", counter);
    }

    kill(childPid, SIGKILL);

    for (int i = 0; i < SHM_I_SIZE; ++i) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}
