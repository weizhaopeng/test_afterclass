#ifndef _ZHOU_DATABASE_H_
#define _ZHOU_DATABASE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


BOOL zhou_check_online(const char *destname);
int  zhou_acquire_hismess(const char *myname, char *message_buf, int *buf_leng);
int  zhou_save_mess(const char *message, int *messlen);

#endif
