#ifndef _ERROR_CHECK_
#define _ERROR_CHECK_

#include <errno.h>
#include <stdio.h>

static inline void data_store_error_check(int error_number)
{
	extern int errno = error_number;
	if (!errno) {
		perror("");
		exit(-1);
	}
}
#endif
