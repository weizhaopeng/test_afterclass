#include "zhou_socket_ser.h"

static inline int listen_accept_fd_pair
			(const int listenfd, int *fd_pair);

int zhou_socket_ser(struct sockaddr_in *cliaddr,
		socklen_t *len, int *chat_pair) {
	int    			   listenfd = 0, ret = 0;
	socklen_t 		   seraddr_len = sizeof(struct sockaddr_in);
	struct sockaddr_in seraddr;

	seraddr.sin_family 		= AF_INET;
	inet_pton(AF_INET, SERVER_IP, &seraddr.sin_addr.s_addr);
	seraddr.sin_port		= htons(SOCK_PORT);

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd == -1) {
		perror("create server socket error");
		return -1;
	}
	
	ret = bind(listenfd, (struct sockaddr *)&seraddr, 
		seraddr_len);
	if (ret == -1) {
		perror("bind socket error");
		return -1;
	}

	ret = listen_accept_fd_pair(listenfd, chat_pair);
	if (ret == -1) {
		perror("accept connect error");
		return -1;
	}

	return 0;
}

//接受fd_pair返回值结果参数
static inline int listen_accept_fd_pair
			(const int listenfd, int *fd_pair) {
	int ret, connfd, sign_connect = 0;

	while (sign_connect != 2) {	
		ret = listen(listenfd, TCP_MAXCONN);
		if (ret == -1)
			return -1;

		connfd = accept(listenfd, NULL, NULL);
			if (connfd == -1)
				return -1;
		fd_pair[sign_connect++] = connfd;
		close(listenfd);
	}
	return 0;
}

//实际上一个服务器地址端口是可以连接多个客户端的
void zhou_close(int *fd_pair) {
	close(fd_pair[0]);
	close(fd_pair[1]);
	return;
}
