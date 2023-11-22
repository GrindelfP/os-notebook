/*
 *  ___  ____    _   _  ___ _____ _____ ____
 * / _ \/ ___|  | \ | |/ _ \_   _| ____/ ___|
 *| | | \___ \  |  \| | | | || | |  _| \___ \
 *| |_| |___) | | |\  | |_| || | | |___ ___) |
 * \___/|____/  |_| \_|\___/ |_| |_____|____/
 *
 * Created on 2023-09-13 by Grindelf P.
 * Stream redirection.
 */

#include <fcntl.h>
#include <iostream>
#include <unistd.h>

int main() {
    int fd = open("new_file_6.adoc", O_CREAT | O_WRONLY, 0666);
    dup2(fd, 1);
    std::cout << "== Here we go again! ==\n";
}
