/*
 *  ___  ____    _   _  ___ _____ _____ ____
 * / _ \/ ___|  | \ | |/ _ \_   _| ____/ ___|
 *| | | \___ \  |  \| | | | || | |  _| \___ \
 *| |_| |___) | | |\  | |_| || | | |___ ___) |
 * \___/|____/  |_| \_|\___/ |_| |_____|____/
 *
 * Created on 2023-11-22 by Grindelf P.
 *
 * Sorting of an integer array with different algorithms in separate threads within one process.
 */

#include <pthread.h>
#include "../seminar_11/shell-sort.h"
#include "../seminar_11/quick-sort.h"
#include "../seminar_11/bubble-sort.h"
#include <fstream>

#define N 1000
#define START 0
#define END (N - 1)

void writeStream(int *array, char *fileName) {
    std::ofstream outputFile(fileName);
    if (!outputFile.is_open()) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < N; ++i) {
        outputFile << array[i] << std::endl;
    }
    outputFile.close();
}

void bubbleThreadFunc(void *impostorArray) {
    int *array = (int *) impostorArray;
    int *copy = new int[N];
    for (int i = 0; i < N; ++i) copy[i] = array[i];
    bubbleSort(array, N);
    writeStream(array, "bubble-sort.txt");
}

void shellThreadFunc(void *impostorArray) {
    int *array = (int *) impostorArray;
    int *copy = new int[N];
    for (int i = 0; i < N; ++i) copy[i] = array[i];
    shellSort(array, N);
    writeStream(array, "shell-sort.txt");
}

void quickThreadFunc(void *impostorArray) {
    int *array = (int *) impostorArray;
    int *copy = new int[N];
    for (int i = 0; i < N; ++i) copy[i] = array[i];
    quickSort(array, START, END);
    writeStream(array, "quick-sort.txt");
}

int main() {

    int *array = new int[N];

    for (int i = 0; i < N; ++i) {
        array[i] = rand() % N;
    }

    pthread_t *thread1 = nullptr;
    int pthread1CreationResult = pthread_create(
            thread1,
            nullptr,
            (void *(*)(void *))bubbleThreadFunc,
            (void *)array
            );
    if (pthread1CreationResult != 0) {
        perror("Error creating thread");
        exit(EXIT_FAILURE);
    }

    pthread_t *thread2 = nullptr;
    int pthread2CreationResult = pthread_create(
            thread2,
            nullptr,
            (void *(*)(void *))shellThreadFunc,
            (void *)array
            );
    if (pthread2CreationResult != 0) {
        perror("Error creating thread");
        exit(EXIT_FAILURE);
    }

    pthread_t *thread3 = nullptr;
    int pthread3CreationResult = pthread_create(
            thread3,
            nullptr,
            (void *(*)(void *))quickThreadFunc,
            (void *)array
            );
    if (pthread3CreationResult != 0) {
        perror("Error creating thread");
        exit(EXIT_FAILURE);
    }


    pthread_join(*thread1, nullptr);
    pthread_join(*thread2, nullptr);
    pthread_join(*thread3, nullptr);

    writeStream(array, "original.txt");

    delete[] array;

    return 0;
}
