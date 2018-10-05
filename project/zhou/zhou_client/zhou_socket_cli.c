#include "zhou_socket_cli.h"

//进行tcp的连接
int zhou_connect(void) {
	int				   connfd = 0, ret = 0;
	socklen_t   	   seraddr_len = sizeof(struct sockaddr);
	struct sockaddr_in seraddr;

	seraddr.sin_family 		= AF_INET;
	seraddr.sin_port   		= htons(ZHOU_PORT);
	ret = inet_pton(AF_INET, IP_SERVER , &seraddr.sin_addr.s_addr);
	if (ret == -1) {
		perror("IP地址转换失败");
		return -1;
	}

	connfd = socket(AF_INET, SOCK_STREAM, 0);
	if (connfd == -1) {
		perror("create socket");
		return -1;
	}

	ret = connect(connfd, (struct sockaddr*)(&seraddr), 
		seraddr_len);
	if (ret == -1) {
		perror("connect the server");
		return -1;
	}
	else {
		system("clear");
		return connfd;
	}
}

//进行tcp的断开
void zhou_disconnect(int connfd) {
	shutdown(connfd, SHUT_WR);
}


