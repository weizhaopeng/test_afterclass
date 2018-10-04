#include "zhou_chat_ser.h"

static inline void data_rw(const int from, const int to);

int zhou_interact(const int *chat_pair) {
	int  nfds    = 2, ret = 0, fd_from = 0, fd_to = 0;
	fd_set rset, wset;

	FD_ZERO(&rset); FD_ZERO(&wset);
	FD_SET(chat_pair[0], &rset);
	FD_SET(chat_pair[1], &rset);
	FD_SET(chat_pair[0], &wset);
	FD_SET(chat_pair[1], &wset);
	
	while (1) {
		ret = select(nfds+1, &rset, &wset, NULL, NULL);
		if (ret > 0) {
			if (FD_ISSET(chat_pair[0], &rset) &&
					FD_ISSET(chat_pair[1], &wset)) {
				fd_from = chat_pair[0];
				fd_to	= chat_pair[1];
				data_rw(fd_from, fd_to);
			}
			if (FD_ISSET(chat_pair[1], &rset) && 
					FD_ISSET(chat_pair[0], &wset)) {
				fd_from = chat_pair[1];
				fd_to	= chat_pair[0];
				data_rw(fd_from, fd_to);
			}
		}
	}
	return 0;
}

static inline void data_rw(const int from, const int to) {
	int  ret = 0;
	char buf[100] = {0};

	do {
		ret = read(from, buf, 100);
	} while(ret <0);
	write(to, buf, 100);
}
