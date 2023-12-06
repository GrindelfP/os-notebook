/*
 *  ___  ____    _   _  ___ _____ _____ ____
 * / _ \/ ___|  | \ | |/ _ \_   _| ____/ ___|
 *| | | \___ \  |  \| | | | || | |  _| \___ \
 *| |_| |___) | | |\  | |_| || | | |___ ___) |
 * \___/|____/  |_| \_|\___/ |_| |_____|____/
 *
 * Created on 2023-12-06 by Grindelf P.
 *
 * Messaging task. Header file for storing message structure.
 */

#ifndef MESSAGE_H
#define MESSAGE_H

struct Message {
    long type;
    char text[1024];
} typedef Message;

#endif
