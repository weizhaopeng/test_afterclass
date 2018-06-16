#include "zhou_socket_cli.h"
#include "zhou_chat_cli.h"

int main(int argc, char *argv[]) {
	int   connfd, ret, status;
	char  *server_ip = argv[1];
	pid_t chat_pid;

	connfd = zhou_connect(server_ip);
	if (connfd == -1) {
		perror("connect");
		return -1;
	}
	
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
