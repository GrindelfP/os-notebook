/*
 *  ___  ____    _   _  ___ _____ _____ ____
 * / _ \/ ___|  | \ | |/ _ \_   _| ____/ ___|
 *| | | \___ \  |  \| | | | || | |  _| \___ \
 *| |_| |___) | | |\  | |_| || | | |___ ___) |
 * \___/|____/  |_| \_|\___/ |_| |_____|____/
 *
 * Created on 2023-10-25 by Grindelf P.
 */

#include <printf.h>

#define TABLE_SEATS 4
#define OCCUPIED 1
#define FREE 0
#define OCCUPATION_LIMIT 3

char phylosopherStates[6][20] = {"thinking", "wants to eat", "takes left fork",
                                 "takes right fork", "eating", "puts forks"
                                };

struct Phylosopher {
    char *currentState;
    char *name;
} typedef Phylosopher;

Phylosopher initPhylosopher(char *name) {
    Phylosopher phylosopher;
    phylosopher.currentState = phylosopherStates[0];
    phylosopher.name = name;
    printf("%s: %s\n", phylosopher.name, phylosopher.currentState);

    return phylosopher;
}

void rotateState(Phylosopher *phylosopher) {
    int i = 0;
    while (phylosopherStates[i] != phylosopher->currentState) i++;
    phylosopher->currentState = phylosopherStates[(i + 1) % 6];
    printf("%s: %s\n", phylosopher->name, phylosopher->currentState);
}

struct Table {
    int *seats;
} typedef Table;

Table initTable() {
    Table table;
    int initialOccupation[TABLE_SEATS] = {FREE, FREE, FREE, FREE};
    table.seats = initialOccupation;

    return table;
}

int occupiedSeatsNumber(Table *table) {
    int occupiedSeats = 0;
    for (int i = 0; i < TABLE_SEATS; i++) {
        if (table->seats[i] == OCCUPIED) occupiedSeats++;
    }

    return occupiedSeats;
}

int occupyNextEmptySeat(Table *table) {
    int phylosopherSeat = 0;
    int numberOfOccupiedSeats = occupiedSeatsNumber(table);
    if  (numberOfOccupiedSeats < OCCUPATION_LIMIT) {
        table->seats[numberOfOccupiedSeats] = OCCUPIED;
    }

    return phylosopherSeat;
}
