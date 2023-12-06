/*
 *  ___  ____    _   _  ___ _____ _____ ____
 * / _ \/ ___|  | \ | |/ _ \_   _| ____/ ___|
 *| | | \___ \  |  \| | | | || | |  _| \___ \
 *| |_| |___) | | |\  | |_| || | | |___ ___) |
 * \___/|____/  |_| \_|\___/ |_| |_____|____/
 *
 * Created on 2023-12-06 by Grindelf P.
 *
 * Messaging task. First messenger, who sends message to second
 * and receives a confirmation.
 */

#include "common.h"
#include "message.h"

int main() {
    std::cout << "I am sender! I send Hello there! " << std::endl;

    int messageQueue = msgget(queue_key, 0666 | IPC_CREAT);

    Message message = {SENDER_TYPE, "Hello there!"};
    msgsnd(messageQueue, &message, sizeof(message.text), 0);

    std::cout << "Message sent. Waiting for confirmation..." << std::endl;

    Message receivedMessage;
    msgrcv(messageQueue, &receivedMessage, sizeof(receivedMessage), RECEIVER_TYPE, 0);
    std::cout << "Confirmation received: " << receivedMessage.text << std::endl;

    return 0;
}
