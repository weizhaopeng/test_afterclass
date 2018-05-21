#ifndef _ZHOU_SOCKET_CLI_H_
#define _ZHOU_SOCKET_CLI_H_

#include <stdio.h>
#include <stdlib>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>

#define serverip 

int zhou_connect(const char *localaddr, const char *destname);
int zhou_disconnect(int connfd);

#endif
