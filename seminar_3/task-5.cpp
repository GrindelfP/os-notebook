/*
 *  ___  ____    _   _  ___ _____ _____ ____
 * / _ \/ ___|  | \ | |/ _ \_   _| ____/ ___|
 *| | | \___ \  |  \| | | | || | |  _| \___ \
 *| |_| |___) | | |\  | |_| || | | |___ ___) |
 * \___/|____/  |_| \_|\___/ |_| |_____|____/
 *
 * Created on 2023-09-13 by Grindelf P.
 * File operations.
 */


#include <fcntl.h>
#include <iostream>
#include <unistd.h>

int main() {
    int fd = open("bb", O_CREAT | O_RDWR, 0666);
    std::cout << fd << std::endl;
    write(fd, "Hello there!", 12);

    char buf[100];

    int k = read(fd, buf, 2);
    int k2 = read(fd, buf, 12);

    std::cout << k << std::endl;
    std::cout << k2 << std::endl;

    close(fd);
    return 0;
}