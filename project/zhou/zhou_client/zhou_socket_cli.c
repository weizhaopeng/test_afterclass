#include "zhou_socket_cli.h"

//进行tcp的连接
int zhou_connect(char *serv_ip) {
	int				   connfd, ret;
	uint32_t		   serverip;
	socklen_t   	   seraddr_len = sizeof(struct sockaddr_in);
	unsigned char 	   buf[NAME_LEN];
	struct sockaddr_in seraddr;

	ret = inet_pton(AF_INET, serv_ip, &seraddr.sin_addr.s_addr);
	if (ret == -1)
		return -1;
	seraddr.sin_family 		= AF_INET;
	seraddr.sin_port   		= htons(ZHOU_PORT);
	seraddr.sin_addr.s_addr = htonl(serverip);

	connfd = socket(AF_INET, SOCK_STREAM, 0);
	if (connfd == -1) {
		perror("create socket");
		return -1;
	}

	ret = connect(connfd, (struct sockaddr *)&seraddr, seraddr_len);
	if (ret == -1) {
		perror("connect");
		return -1;
	}
	else {
		system("clear");
		puts("连接成功\n");
		return connfd;
	}
}

//进行tcp的断开
int zhou_disconnect(int connfd) {
	shutdown(connfd, SHUT_WR);
}


