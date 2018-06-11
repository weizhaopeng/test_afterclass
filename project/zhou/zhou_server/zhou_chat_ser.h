#ifndef _ZHOU_CHAT_SER_H_
#define _ZHOU_CHAT_SER_H_

#include <stdio.h>
#include <errno.h>
#include <sys/select.h>
#include <unistd.h>

int zhou_interact(const int *fd_pair);

#endif

