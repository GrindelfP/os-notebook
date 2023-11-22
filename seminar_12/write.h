//
// Created by Gregory Shipunov on 11/22/23.
//

#ifndef OS_NOTEBOOK_WRITE_H
#define OS_NOTEBOOK_WRITE_H

#include <fstream>

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

#endif //OS_NOTEBOOK_WRITE_H
