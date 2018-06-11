#include "zhou_socket_ser.h"

int zhou_socket_ser(struct sockaddr_in *cliaddr,
		socklen_t *len, int *chat_pair) {
	int    			   listenfd, connfd, connnum, ret;
	socklen_t 		   seraddr_len = sizeof(struct sockaddr_in);
	struct sockaddr_in seraddr;

	seraddr.sin_family 		= AF_INET;
	seraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	seraddr.sin_port		= htons(SOCK_PORT);

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd == -1)
		return -1;
	
	ret = bind(listenfd, (struct sockaddr *)&seraddr,
					seraddr_len);
	if (ret == -1) 
		return -1;
	
	listenfd = listen(listenfd, TCP_MAXCONN);
	if (listenfd == -1)
		return -1;

	while (connnum != 2) {
		connfd = accept(listenfd, (struct sockaddr*)cliaddr, len);
		if (connfd == -1)
			return -1;
		else
			chat_pair[++connnum] = connfd;
	}
	return 0;
}

//实际上一个服务器地址端口是可以连接多个客户端的
void zhou_close(int *fd_pair) {
	close(fd_pair[0]);
	close(fd_pair[1]);
	return;
}
