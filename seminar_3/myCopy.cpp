/*
 *  ___  ____    _   _  ___ _____ _____ ____
 * / _ \/ ___|  | \ | |/ _ \_   _| ____/ ___|
 *| | | \___ \  |  \| | | | || | |  _| \___ \
 *| |_| |___) | | |\  | |_| || | | |___ ___) |
 * \___/|____/  |_| \_|\___/ |_| |_____|____/
 *
 * Created on 2023-09-13 by Grindelf P.
 */

#include "myCopy.hpp"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Incorrect number of arguments!" << std::endl;
    } else {
        int copyResult = myCopy(argv[1], argv[2]);
        if (copyResult == 0) {
            std::cout << "Copy successful!" << std::endl;
        } else {
            std::cout << "Copy failed!" << std::endl;
        }
    }

    return 0;
}

/*
 * Copies fileFrom to fileTo. Returns 0 if success, -1 if error occurred.
 */
int myCopy(char *fileFrom, char *fileTo) {
    char buffer[BUFFER_SIZE];
    int fdFrom = open(fileFrom, O_RDONLY);
    int fdTo = open(fileTo, O_CREAT | O_WRONLY, 0666);
    if (checkError(fdFrom)) return -1;
    ssize_t readResult = read(fdFrom, buffer, BUFFER_SIZE);
    if (checkError((int)readResult)) return -1;

    while (readResult != 0) {
        ssize_t writeResult = write(fdTo, buffer, readResult);
        readResult = read(fdFrom, buffer, BUFFER_SIZE);
        if (checkError((int)writeResult) || checkError((int)readResult)) return -1;
    }

    close(fdTo);
    close(fdFrom);

    return 0;
}

/*
 * Checks if error code -1 is returned. Returns 0 if error code is raised, -1 otherwise.
 */
int checkError(int errorCode) {
    int errorPresent = 0;
    if (errorCode == -1) {
        errorPresent = 1;
    }

    return errorPresent;
}
