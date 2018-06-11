#include "zhou_chat_ser.h"

int zhou_interact(const int *chat_pair) {
	int    		   nfds = 2, sigmess_t, ret,
				   fd_from, fd_to;
	char   		   buf_recv[100], buf_send[100];
	fd_set 		   rset, wset;
	struct timeval timeout = {
		.tv_sec  = 20,
		.tv_usec = 20
	};

	FD_SET(chat_pair[0], &rset);
	FD_SET(chat_pair[1], &rset);
	FD_SET(chat_pair[0], &wset);
	FD_SET(chat_pair[1], &wset);
	
	while (1) {
		ret = select(nfds+1, &rset, &wset, NULL, &timeout);
		if (ret > 0) {
			if (FD_ISSET(chat_pair[0], &rset) && 
					FD_ISSET(chat_pair[1], &wset)) {
				fd_from = chat_pair[0];
				fd_to	= chat_pair[1];
				sigmess_t = 1;
			}
			if (FD_ISSET(chat_pair[1], &rset) && 
					FD_ISSET(chat_pair[0], &wset)) {
				fd_from = chat_pair[1];
				fd_to	= chat_pair[0];
				sigmess_t = 1;
			}

			if (sigmess_t) {
				ret = read(fd_from, buf_recv, 100);
				write(fd_to, buf_send, 100);
				sigmess_t = 0;
				if (ret == 0)
					return 0;
				else if (ret == -1)
					return -1;
			}
		}
	}
	return 0;
}
