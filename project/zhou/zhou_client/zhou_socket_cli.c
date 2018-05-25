#include "zhou_socket.h"

//进行tcp的连接
int zhou_connect(const uint32_t localaddr, 
			const char *localname, const char *destname) {
	unsigned char 	   buf[NAME_LEN];
	struct sockaddr_in cliaddr, seraddr;
	socklen_t 		   clilen = sizeof(cliaddr);
	cliaddr.sin_family 		  = AF_INET;
	cliaddr,sin_addr.s_addr   = htonl(localaddr);
	cliaddr.sin_port 	   	  = htons(ZHOU_PORT);

	connfd = socket(AF_INET, SOCK_STREAM, 0);
	if (connnfd == -1) {
		perror("create socket");
		return -1;
	}

	ret = connect(connfd, &cliaddr, clilen);
	if (ret == -1) {
		perror("connect");
		return -1;
	}
	else return connfd;
}

//进行tcp的断开
int zhou_disconnect(int connfd) {
	shutdown(connfd, SHUT_WR);
}


