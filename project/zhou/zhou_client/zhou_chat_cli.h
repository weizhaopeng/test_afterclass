#ifndef _ZHOU_CHAT_H_
#define _ZHOU_CHAT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <errno.h>
#include <poll.h>
#include <strings.h>
#include <sys/socket.h>

#define BUF_SEND_CAP 100
#define BUF_RECV_CAP 100

#define ENOHOST		 1
#define ENOCONNECT	 2
#define ENOONLINE 	 4

int zhou_chat(int connfd);

#endif 
