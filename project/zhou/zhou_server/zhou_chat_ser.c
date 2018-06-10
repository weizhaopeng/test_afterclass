#include "zhou_chat.h"

int zhou_interact(const int *chat_pair) {
	int    nfds1 = 2;
	fd_set rfd, wfd;
	struct timeval timeout = {
		.tv_sec  = 20,
		.tv_usec = 20
	};

	FD_SET(chat_pair[0], &rfd);
	FD_SET(chat_pair[1], &rfd);
	FD_SET(chat_pair[0], &wfd);
	FD_SET(chat_pair[1], &wfd);

	while (1) {
		ret = select(nfds+1, &rfd, &wfd, NULL, &timeout);
		if (ret > 0) {
			if (FD_ISSET(chat_pair[0], &rfd) && 
					FD_ISSET(chat_pair[1], &wfd)) {
				ret = zhou_(chat_pair[0], chat_pair[1]);
				if (ret == 0)
					zhou_close(chat_pair);
				else if (ret == -1)
					return -1;
			}


}
