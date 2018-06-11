#include "zhou_chat_ser.h"
#include "zhou_socket_ser.h"

int main(int argc, char *argv[]) {
	//初始化变量
	int 	  		   fd_pair[2], ret;
	socklen_t 		   cliaddr_len;
	struct sockaddr_in cliaddr;

	//进行tcp连接
	ret = zhou_socket_ser(&cliaddr, &cliaddr_len, fd_pair);
	if (ret == -1) {
		perror("connect:");
		return -1;
	}
	//进行聊天
	ret = zhou_interact(fd_pair);
	if (ret == -1) {
		perror("chat:");
		return -1;
	}
	//断开连接
	if (ret == 0) 
		zhou_close(fd_pair);
	return 0;
}
