#ifndef _ZHOU_SOCKET_SER_H_
#define _ZHOU_SOCKET_SER_H_

#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SOCK_PORT   5050
#define TCP_MAXCONN 20
#define SOCK_IP_SERVER "172.16.252.209"

//形参：客户端地址结构，地址长度，聊天描述符对
int
zhou_socket_ser(int *chat_pair);
void
zhou_close(int *fd_pair);

#endif
