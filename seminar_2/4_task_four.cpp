/*
 *  ___  ____    _   _  ___ _____ _____ ____
 * / _ \/ ___|  | \ | |/ _ \_   _| ____/ ___|
 *| | | \___ \  |  \| | | | || | |  _| \___ \
 *| |_| |___) | | |\  | |_| || | | |___ ___) |
 * \___/|____/  |_| \_|\___/ |_| |_____|____/
 *
 * Created on 2023-09-13 by Grindelf P.
 */

#include <iostream>
#include "../headers/commons.hpp"

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; ++i) {
        print(argv[i]);
    }

    return 0;
}
