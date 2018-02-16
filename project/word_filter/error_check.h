#include <errno.h>
static inline void data_store_error_check(int error_number)
{
	extern int errno = error_number;
	if (!errno) {
		perror("");
		exit(-1);
	}
}
