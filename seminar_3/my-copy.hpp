/*
 *  ___  ____    _   _  ___ _____ _____ ____
 * / _ \/ ___|  | \ | |/ _ \_   _| ____/ ___|
 *| | | \___ \  |  \| | | | || | |  _| \___ \
 *| |_| |___) | | |\  | |_| || | | |___ ___) |
 * \___/|____/  |_| \_|\___/ |_| |_____|____/
 *
 * Created on 2023-09-13 by Grindelf P.
 */


#ifndef OS_3RDTERM_MY_COPY_HPP
#define OS_3RDTERM_MY_COPY_HPP

#include <iostream>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 24

/*
 * Copies fileFrom to fileTo. Returns 0 if success, -1 if error occurred.
 */
int myCopy(char *fileFrom, char *fileTo);

/*
 * Checks if error code -1 is returned. Returns 0 if error code is raised, -1 otherwise.
 */
int checkError(int errorCode);

#endif //OS_3RDTERM_MY_COPY_HPP
