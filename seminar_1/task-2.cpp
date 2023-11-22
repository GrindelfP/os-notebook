/*
 *  ___  ____    _   _  ___ _____ _____ ____
 * / _ \/ ___|  | \ | |/ _ \_   _| ____/ ___|
 *| | | \___ \  |  \| | | | || | |  _| \___ \
 *| |_| |___) | | |\  | |_| || | | |___ ___) |
 * \___/|____/  |_| \_|\___/ |_| |_____|____/
 *
 * Created on 2023-09-06 by Grindelf P.
 * Multiple processes creation. Parent waits for all children to finish.
 */

#include <unistd.h>
#include <sys/wait.h>

#include "../headers/commons.hpp"

int main() {

    for (int i = 0; i < 3; ++i) {
        if (!fork()) {
            printFour("Child", i + 1, getpid(), getppid);
            return 0;
        }
    }
    printTwo("Parent ", getpid());

    int resultChildOne;
    int ppOne = wait(&resultChildOne);
    printTwo("Child stopped: ", ppOne);

    int resultChildTwo;
    int ppTwo = wait(&resultChildTwo);
    printTwo("Child stopped: ", ppTwo);

    int resultChildThree;
    int ppThree = wait(&resultChildThree);
    printTwo("Child stopped: ", ppThree);

    print("Parent stopped");

    return 0;
}
