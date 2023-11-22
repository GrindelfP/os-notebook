/*
 *  ___  ____    _   _  ___ _____ _____ ____
 * / _ \/ ___|  | \ | |/ _ \_   _| ____/ ___|
 *| | | \___ \  |  \| | | | || | |  _| \___ \
 *| |_| |___) | | |\  | |_| || | | |___ ___) |
 * \___/|____/  |_| \_|\___/ |_| |_____|____/
 *
 * Created on 2023-11-15 by Grindelf P.
 *
 * Sorting of an integer array with different algorithms in separate processes.
 */

#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include "shell-sort.h"
#include "quick-sort.h"
#include "bubble-sort.h"

#define N 1000


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


int main() {
    int *array = new int[N];

    for (int i = 0; i < N; ++i) {
        array[i] = rand() % N;
    }

    if (!fork()) {
        if (!fork()) {
            if (!fork()) {
                // third child: qsort
                quickSort(array, 0, N - 1);
                writeStream(array, "qsort.txt");
            } else {
                // second child: shell
                shellSort(array, N);
                writeStream(array, "shellSort.txt");
            }
        } else {
            // first child: bubble
            bubbleSort(array, N);
            writeStream(array, "bubbleSort.txt");

        }
    } else {
        writeStream(array, "numbers.txt");
    }

    return 0;
}
