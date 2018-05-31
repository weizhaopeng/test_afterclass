#include "zhou_socket_ser.h"

int zhou_socket_ser(struct sockaddr_in *cliaddr, socklen_t *len) {
	int listenfd, connfd;
	struct sockaddr_in seraddr;
	struct socklen_t seraddr_len = sizeof(seraddr);

	seraddr.sin_family 		= AF_INET;
	seraddr.sin_addr.s_addr = htonl(INETADDR_ANY);
	seraddr.sin_port		= htons(SOCK_PORT);

	listenfd = socket(AF_INET, &seraddr, seraddr_len);
	if (listenfd == -1)
		return -1;
	
	ret = bind(listenfd, &seraddr, seraddr_len);
	if (ret == -1) 
		return -1;
	
	ret = listen(listenfd, TCP_MAXCONN);
	if (connfd == -1)
		return -1;
	
	connfd = accept(connfd, cliaddr, len);
	if (connfd == -1)
		return -1;
	else
		return connfd;
}
