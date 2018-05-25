#include "zhou_socket_cli.h"
#include "zhou_chat_cli.h"

int main(int argc, char *argv[]) {
	//输入格式提示
	if (argc != 3) {
		printf("参数输入格式：./client <用户名> <服务器IP地址>");
		return 0;
	}
	//初始化变量
	char *localhost = argv[1], localname[20], destname[20];
	uint32_t serveraddr;
	int connfd, ret;
	
	//输入连接信息，进行tcp连接
	ret = inet_pton(AF_INET, argv[2], serveraddr);
	if (ret == 0) {
		puts("服务器地址格式错误");
		return -1;
	}
	else if (ret == -1) {
		perror("addr translate");
		return -1;
	}

	puts("请输入昵称\n");
	scanf("%s", localname);
	fflush(stdin);
	puts("请输入发送信息用户昵称\n");
	scanf("%s", destname);

	connfd = zhou_connect(serveraddr, localname, destname);
	//根据提示信息进行信息发送和信息接收
	ret = zhou_chat(connfd);
	if (ret == -1) {
		perror("chat");
		return -1;
	}
	//断开连接
	zhou_disconnect(connfd);
}
