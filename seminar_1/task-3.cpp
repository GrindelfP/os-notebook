/*
 *  ___  ____    _   _  ___ _____ _____ ____
 * / _ \/ ___|  | \ | |/ _ \_   _| ____/ ___|
 *| | | \___ \  |  \| | | | || | |  _| \___ \
 *| |_| |___) | | |\  | |_| || | | |___ ___) |
 * \___/|____/  |_| \_|\___/ |_| |_____|____/
 *
 * Created on 2023-09-06 by Grindelf P.
 * Simple example of execlp() function and the execution of a shell command in a C/C++ program.
 */

#include <unistd.h>

#include "../headers/commons.hpp"

int main() {

    execlp("ls", "ls", "-la", NULL); // destroys program after the result of the command
    print("Hello there!");

    return 0;
}
