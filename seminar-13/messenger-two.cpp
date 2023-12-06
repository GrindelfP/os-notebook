/*
 *  ___  ____    _   _  ___ _____ _____ ____
 * / _ \/ ___|  | \ | |/ _ \_   _| ____/ ___|
 *| | | \___ \  |  \| | | | || | |  _| \___ \
 *| |_| |___) | | |\  | |_| || | | |___ ___) |
 * \___/|____/  |_| \_|\___/ |_| |_____|____/
 *
 * Created on 2023-12-06 by Grindelf P.
 *
 * Messaging task. Second messenger, who receives message from the first
 * and sends a confirmation.
 */

#include "common.h"
#include "message.h"

int main() {
    std::cout << "I am receiver! I send confirmation" << std::endl;

    int messageQueue = msgget(queue_key, 0666 | IPC_CREAT);
    if (messageQueue < 0) {
        std::cout << "Error creating message queue!" << std::endl;
        return 1;
    }

    std::cout << "Waiting for message..." << std::endl;

    Message receivedMessage;
    if (msgrcv(messageQueue, &receivedMessage, sizeof(receivedMessage), SENDER_TYPE, 0)) {
        std::cout << "Message received: " << receivedMessage.text << std::endl;
        Message confirmationMessage = {RECEIVER_TYPE, "Message received!"};
        msgsnd(messageQueue, &confirmationMessage, sizeof(confirmationMessage), 0);
        std::cout << "Confirmation sent!" << std::endl;
    } else {
        std::cout << "No message received!" << std::endl;
    }

    return 0;
}
