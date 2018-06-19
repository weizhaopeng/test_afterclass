#include "zhou_socket_cli.h"
#include "zhou_chat_cli.h"

const char *ip_serv = "129.79.130.38";

int main(int argc, char *argv[]) {
	int    connfd, ret, status;
	pid_t  chat_pid;
	char  *server_ip = "172.16.252.209";

	connfd = zhou_connect(server_ip);
	if (connfd == -1) {
		perror("connect");
		return -1;
	}
	else puts("连接成功\n");
	
	chat_pid = fork();
	if (chat_pid == 0) {
		ret = zhou_chat(connfd);
		if (ret == -1) {
			perror("chat");
			exit(-1);
		}
		exit(0);
	}

	if (chat_pid > 0) {
		zhou_disconnect(connfd);
		waitpid(chat_pid, &status, 0);
		exit(0);
	}
}
