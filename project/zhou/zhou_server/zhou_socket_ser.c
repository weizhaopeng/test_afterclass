#include "zhou_socket_ser.h"

int zhou_socket_ser(int *chat_pair) {
	int 	  listenfd = 0, ret = 0, addr_h = 0;
	//pid_t	  child_pid[2] = {0};
	socklen_t seraddr_len = sizeof(struct sockaddr);
	struct sockaddr_in seraddr;

	ret = inet_pton(AF_INET, SOCK_IP_SERVER, &addr_h);
	if (ret == -1) {
		perror("translate address failed");
		return -1;
	}
	seraddr.sin_family 		= AF_INET;
	seraddr.sin_addr.s_addr = addr_h;
	seraddr.sin_port		= htons(SOCK_PORT);

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if (listenfd == -1) {
		perror("create server socket error");
		return -1;
	}
	
	ret = bind(listenfd, (struct sockaddr*)(&seraddr), seraddr_len);
	if (ret == -1) {
		perror("bind socket error");
		return -1;
	}

	for (int i = 0; i < 2; i++) {
		ret = listen(listenfd, TCP_MAXCONN);
		if (ret == 0) {
			child[i] = fork() {
				if (child[i] == 0) {
					connfd = accept(listenfd, NULL, NULL);
					if (connfd == -1) {
						perror("require accept failed");
						return -1;
					}

	puts("the fd pair has connected");
	return 0;
}

//实际上一个服务器地址端口是可以连接多个客户端的
void zhou_close(int *fd_pair) {
	close(fd_pair[0]);
	close(fd_pair[1]);
	return;
}
