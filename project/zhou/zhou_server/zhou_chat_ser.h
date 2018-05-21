#ifndef _ZHOU_CHAT_SER_H_
#define _ZHOU_CHAT_SER_H_

#include "zhou_interact.h"
#include "zhou_database.h"

int zhou_interact(const int srcfd, const int destfd);
int zhou_database(const int action, const char *buf, int *buf_leng);

#endif

