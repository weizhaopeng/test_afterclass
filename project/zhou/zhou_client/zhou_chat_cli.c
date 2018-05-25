#include "zhou_chat.h"

static inline int zhou_get_status(const int connfd);
static inline int zhou_nonline	 (const int connfd);
static inline int zhou_online	 (const int connfd);
static inline void zhou_interface(void);

//给定接口进行聊天
int zhou_chat(const int connfd) {
	int ret;
	//初始聊天进行对方状态确认:-1：出错， 0：对方不在线，1:对方在线 
	ret = zhou_get_status(connfd);
	switch(ret) {
		case -1: return -1;

		case 1://返回值是-1出错，为0正常断开， 为1对方掉线
			ret = zhou_online(connfd);
			if (ret == -1) 
				return -1;
			else 
				if (ret == 0)
					break;

		case 0:
			ret = zhou_nonline(connfd);
			if (ret == -1) return -1;
			break;
			
		default:
	}
	return 0;
}

static inline int zhou_get_status(const int connfd, 
				const char *myname, const char *desthost) {
	struct pollfd fds[2];
	int    fdnum = 2, timeout = 30, len_l, len_d;
	char   buf[100];
	int    sign

	fds[0].fd 	   = connfd;
	fds[1].fd 	   = connfd;
	fds[0].events  = POLLIN;
	fds[1].events  = POLLOUT;
	fds[0].revents = 0;
	fds[1].revents = 0;

	ret = poll(fds, fdnum, timeout);
	if (ret == -1) {
		perror("poll");
		return -1;
	}

	if (fds[1].revents) {
		memset(buf, 0, 100);
		len_l = strlen(myname);
		len_d = strlen(desthost);
		memcpy(buf, myname, len_l);
		buf[len_l] = '\0';
		memcpy(buf+len_l+1, desthost, len_d);
		
		write(connfd, buf, 100);
	}

	
	/*while(1) {
		ret = poll(fds, fdnum, timeout);
		if (ret == -1) {
			perror("poll");
			return -1;
		}
		if (fds[0].revents) {
			ret = read(STDIN_FILENO, buf_send,BUF_SEND_CAP);
			switch (ret) {
				case 0:
					shutdown(connfd, SHUT_WR);
					break;
				case -1:
					perror("read messege");
					return -1;
					break;
				default:
					write(connfd, buf_send, ret);
					break;
			}
		}*/
	//被动接受信息
		if (fds[1].revents) {
			ret = read(connfd, buf_recv, BUF_RECV_CAP);
			if (ret == -1)
				return -1;
			ret = zhou_interface(buf_recv[0], buf_recv+1, ret-1);
			if (ret == -1)
				return -1;
		}
	}
}

//界面信息消息显示
//连接后接受到服务器发送的字段，第一个字节用于告知要连接的主机的状态
static inline int zhou_interface(const char sign, 
				char *mess, const int mess_len) {
	zhou_backgrand();
	switch (sign) {
		case 0x00:
			printf("%40s\n", mess);
			break;
		case 0x01:
			printf("%40s\n", "好友不在线，可以离线留言");
			break;
		case 0x02:
			printf("%40s\n", "找不到好友");
			break;
		default:
	}
}

//确认目标状态
static inline int zhou_get_status(const int connfd) {
	

