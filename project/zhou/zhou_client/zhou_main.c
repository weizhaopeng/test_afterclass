#include "zhou_socket_cli.h"
#include "zhou_chat_cli.h"

int main(int argc, char *argv[]) {
	int    connfd = 0, ret = 0;
	pid_t  chat_pid = 0;
	//连接服务器
	connfd = zhou_connect();
	if (connfd == -1) {
		perror("连接");
		return 1;
	}
	else puts("连接成功\n");
	//进行聊天	
	ret = zhou_chat(connfd);
	if (ret == -1)
		perror("聊天");
	else
		puts("聊天结束");
	//断开连接
	if (chat_pid > 3) {
		zhou_disconnect(connfd);
		puts("断开连接完成");
	}
	else
		puts("无法断开连接");
	
	return ret;
}
