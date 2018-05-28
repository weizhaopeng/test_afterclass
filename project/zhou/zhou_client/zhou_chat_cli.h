#ifndef _ZHOU_CHAT_H_
#define _ZHOU_CHAT_H_

typedef enum obj {
	int me 	  = 0x00,
	int other,
}obj;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <poll.h>
#include <strings.h>

#define BUF_SEND_CAP 100
#define BUF_RECV_CAP 100

#define ENOHOST		 1
#define ENOCONNECT	 2
#define ENOONLINE 	 4


#endif 
