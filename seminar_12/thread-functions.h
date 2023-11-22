/*
 *  ___  ____    _   _  ___ _____ _____ ____
 * / _ \/ ___|  | \ | |/ _ \_   _| ____/ ___|
 *| | | \___ \  |  \| | | | || | |  _| \___ \
 *| |_| |___) | | |\  | |_| || | | |___ ___) |
 * \___/|____/  |_| \_|\___/ |_| |_____|____/
 *
 * Created on 2023-11-22 by Grindelf P.
 *
 * Header file for thread functions.
 */

#ifndef OS_NOTEBOOK_THREAD_FUNCTIONS_H
#define OS_NOTEBOOK_THREAD_FUNCTIONS_H

#include "write.h"
#include "common.h"
#include "../seminar_11/bubble-sort.h"
#include "../seminar_11/shell-sort.h"
#include "../seminar_11/quick-sort.h"

void *bubble(void *arg) {
    int *array = reinterpret_cast<int *>(arg);
    int *copyArray = new int[N];
    std::copy(array, array + N, copyArray);

    bubbleSort(copyArray, N);

    writeStream(copyArray, "../output/bubble-sort.txt");

    delete[] copyArray;

    return nullptr;
}

void *shell(void *arg) {
    int *array = reinterpret_cast<int *>(arg);
    int *copyArray = new int[N];
    std::copy(array, array + N, copyArray);

    shellSort(copyArray, N);

    writeStream(copyArray, "../output/shell-sort.txt");

    delete[] copyArray;

    return nullptr;
}

void *quick(void *arg) {
    int *array = reinterpret_cast<int *>(arg);
    int *copyArray = new int[N];
    std::copy(array, array + N, copyArray);

    quickSort(copyArray, 0, N - 1);

    writeStream(copyArray, "../output/quick-sort.txt");

    delete[] copyArray;

    return nullptr;
}

#endif //OS_NOTEBOOK_THREAD_FUNCTIONS_H
