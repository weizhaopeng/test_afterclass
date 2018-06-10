#ifndef _ZHOU_SOCKET_SER_H_
#define _ZHOU_SOCKET_SER_H_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include "zhou_datebase.h"

#define SOCK_PORT
#define TCP_MAXCONN 20

//形参：客户端地址结构，地址长度，聊天描述符对缓冲区
int zhou_socket_ser(struct sockaddr_in *cliaddr,
		socklen_t *len, int *chat_pair);
#endif
