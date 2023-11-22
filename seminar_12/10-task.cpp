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
#include <iostream>
#include "common.h"
#include "thread-functions.h"


int main() {

    int *array = new int[N];

    for (int i = 0; i < N; ++i) {
        array[i] = rand() % N;
    }

    pthread_t bubbleThread;
    if (pthread_create(&bubbleThread, nullptr, bubble, array) != 0) {
        std::cerr << "Failed to create bubbleThread" << std::endl;
        return 1;
    }

    pthread_t shellThread;
    if (pthread_create(&shellThread, nullptr, shell, array) != 0) {
        std::cerr << "Failed to create shellThread" << std::endl;
        return 1;
    }

    pthread_t quickThread;
    if (pthread_create(&quickThread, nullptr, quick, array) != 0) {
        std::cerr << "Failed to create quickThread" << std::endl;
        return 1;
    }

    if (pthread_join(bubbleThread, nullptr) != 0) {
        std::cerr << "Failed to join bubbleThread" << std::endl;
        return 1;
    }

    if (pthread_join(shellThread, nullptr) != 0) {
        std::cerr << "Failed to join shellThread" << std::endl;
        return 1;
    }

    if (pthread_join(quickThread, nullptr) != 0) {
        std::cerr << "Failed to join quickThread" << std::endl;
        return 1;
    }

    writeStream(array, "../output/original.txt");

    delete[] array;

    return 0;
}
