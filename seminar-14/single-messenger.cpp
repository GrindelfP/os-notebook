/*
 *  ___  ____    _   _  ___ _____ _____ ____
 * / _ \/ ___|  | \ | |/ _ \_   _| ____/ ___|
 *| | | \___ \  |  \| | | | || | |  _| \___ \
 *| |_| |___) | | |\  | |_| || | | |___ ___) |
 * \___/|____/  |_| \_|\___/ |_| |_____|____/
 *
 * Created on 2023-11-22 by Grindelf P.
 *
 * Sender and receiver of messages. If provided with arg 's' then send, if provided with arg 'r' then receive.
 */

#include <iostream>
#include "common.h"
#include "message.h"


int main(int argc, char *argv[]) {
    // 1. if s then get input, if input != '' then send, else stop
    // 2. if r then receive and print and stop

    if (argc < 3) { THROW_ARGUMENT_EXCEPTION; }
    char arg = argv[1][0];
    int key = atoi(argv[2]);

    int messageQueue = msgget(queue_key, 0666 | IPC_CREAT);
    if (messageQueue < 0) { THROW_MESSAGE_QUEUE_EXCEPTION; }

    if (arg == SENDER) {
        Message message;
        message.type = key;
        std::cout << "Enter message (if you want to stop messaging just hit Enter):\n";
        char messageLine[128];
        while (true) {
            std::cin.getline(messageLine, MESSAGE_SIZE);
            strlcat(messageLine, message.text, MESSAGE_SIZE);
            if (strcmp(message.text, "") == 0) break;
        }
        std::cout << "Sending message..." << std::endl;
        msgsnd(messageQueue, &message, strlen(message.text) + 1, 0);
        return 0;
    } else if (arg == RECEIVER) {
        Message message;
        while (msgrcv(messageQueue, &message, sizeof(message.text) + 1, key, IPC_NOWAIT) != -1) {
            std::cout << "Message received: " << message.text << std::endl;
        }
        return 0;
    } else std::cout << "Invalid input" << std::endl;

    return 0;
}
