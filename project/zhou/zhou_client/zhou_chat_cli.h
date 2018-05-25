#ifndef _ZHOU_CHAT_H_
#define _ZHOU_CHAT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUF_SEND_CAP 100
#define BUF_RECV_CAP 100

#define ENOHOST		 1
#define ENOCONNECT	 2
#define ENOONLINE 	 4

static inline int zhou_chat(const int connfd);

#endif 
