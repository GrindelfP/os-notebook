/*
 *  ___  ____    _   _  ___ _____ _____ ____
 * / _ \/ ___|  | \ | |/ _ \_   _| ____/ ___|
 *| | | \___ \  |  \| | | | || | |  _| \___ \
 *| |_| |___) | | |\  | |_| || | | |___ ___) |
 * \___/|____/  |_| \_|\___/ |_| |_____|____/
 *
 * Created on 2023-10-25 by Grindelf P.
 */

#include <unistd.h>
#include "phylosopher.h"

int names[4] = {1, 2, 3, 4};

int maitredhotel(Table *table, Phylosopher *phylosopher) {
    for (int i = 0; i < TABLE_SEATS; ++i) {
        printf("%d ", table->seats[i]);
    }

    if (occupyNextEmptySeat(table)) {
        rotateState(phylosopher);
    }

    printf("Table: %d\n", occupiedSeatsNumber(table));

    return 0;
}

int main() {



    return 0;
}

