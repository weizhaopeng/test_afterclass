#ifndef _ZHOU_SOCKET_CLI_H_
#define _ZHOU_SOCKET_CLI_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>

#define serverip 
#define NAME_LEN  100
#define ZHOU_PORT 5050

int zhou_connect(const uint32_t serveraddr, 
		const char *localname, const char *destname);
int zhou_disconnect(int connfd);

#endif
