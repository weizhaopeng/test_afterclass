#ifndef _ZHOU_SOCKET_CLI_H_
#define _ZHOU_SOCKET_CLI_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <wait.h>

#define NAME_LEN  100
#define ZHOU_PORT 5555
#define IP_SERVER 127.0.0.1

int  zhou_connect(char *serv_ip);
void zhou_disconnect(int connfd);

#endif
