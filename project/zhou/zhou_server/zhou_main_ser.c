#include "zhou_chat_ser.h"
#include "zhou_socket_ser.h"

int main(int argc, char *argv[]) {
	//初始化变量
	int 			   fd_pair[2] = {0}, ret = 0;
	socklen_t 		   cliaddr_len = 0;
	struct sockaddr_in cliaddr;
	puts("初始化变量");

	//进行tcp连接
	ret = zhou_socket_ser(&cliaddr, &cliaddr_len, fd_pair);
	if (ret == -1) {
		perror("客户端服务器连接失败:");
		return -1;
	}
	else
		puts("客户端服务器连接成功");

	//进行聊天
	ret = zhou_interact(fd_pair);
	if (ret == -1)
		perror("聊天过程发生错误:");
	else
		puts("聊天结束bye");
	//断开连接
	zhou_close(fd_pair);
	return 0;
}
