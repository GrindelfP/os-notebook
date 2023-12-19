/*
 *  ___  ____    _   _  ___ _____ _____ ____
 * / _ \/ ___|  | \ | |/ _ \_   _| ____/ ___|
 *| | | \___ \  |  \| | | | || | |  _| \___ \
 *| |_| |___) | | |\  | |_| || | | |___ ___) |
 * \___/|____/  |_| \_|\___/ |_| |_____|____/
 *
 * Created on 2023-12-06 by Grindelf P.
 *
 * Messaging task. Header file for storing common headers for both communication programs.
 */

#ifndef COMMON_H
#define COMMON_H

#include <sys/msg.h>
#include <iostream>

#define queue_key 122331
#define SENDER_TYPE 1
#define RECEIVER_TYPE 2
#define THROW_ARGUMENT_EXCEPTION std::cerr << "Invalid input" << std::endl; return 1
#define THROW_MESSAGE_QUEUE_EXCEPTION std::cout << "Error creating message queue!" << std::endl; return 1
#define SENDER 's'
#define RECEIVER 'r'

#endif
