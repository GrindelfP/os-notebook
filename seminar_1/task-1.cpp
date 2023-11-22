/*
 *  ___  ____    _   _  ___ _____ _____ ____
 * / _ \/ ___|  | \ | |/ _ \_   _| ____/ ___|
 *| | | \___ \  |  \| | | | || | |  _| \___ \
 *| |_| |___) | | |\  | |_| || | | |___ ___) |
 * \___/|____/  |_| \_|\___/ |_| |_____|____/
 *
 * Created on 2023-09-06 by Grindelf P.
 * Introduction to fork() function and processes' creation
 */

#include <unistd.h>
#include <iostream>

int main() {
    int forked_id = fork();
    if (forked_id) {
        std::cout << "One " << forked_id << "\n";
    } else {
        std::cout << "Two " << forked_id << "\n";
    }

    return 0;
}
