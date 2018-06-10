#include "zhou_chat_cli.h"

int zhou_chat(int connfd) {
	int  		  fdsnum = 3, timeout = 20, ret, sign_stop = 0;
	char		  buf_send[BUF_SEND_CAP], buf_recv[BUF_RECV_CAP];
	struct pollfd fd[3];
	
	fd[0].fd 	 = connfd;
	fd[0].events = POLLIN;
	fd[1].fd 	 = connfd;
	fd[1].events = POLLOUT;
	fd[2].fd	 = STDIN_FILENO;
	fd[2].events = POLLIN;

	while (!sign_stop) {
		ret = poll(fd, fdsnum, timeout);
		if (ret == -1) {
			perror("poll");
			return -1;
		}
		//如果键盘有输入信息
		if (fd[1].revents == POLLIN) {
			if (fd[1].revents == POLLOUT) {
				ret = read(STDIN_FILENO, buf_send, BUF_SEND_CAP);
				if (ret == 0) {
					shutdown(connfd, SHUT_WR);
					sign_stop = 1;
				}
				write(connfd, buf_send, BUF_SEND_CAP);

				bzero(buf_send, BUF_SEND_CAP);
				fflush(stdin);
			}
		}
		//如果从网口有数据发送回来
		if (fd[0].revents == POLLIN) {
			ret = read(connfd, buf_recv, BUF_RECV_CAP);
			if (ret == 0) {
				close(connfd);
				sign_stop = 1;
			}
			write(STDOUT_FILENO, buf_recv, BUF_RECV_CAP);
		}
	}
}


			



/*
static inline int zhou_get_status(const int connfd);
static inline int zhou_nonline	 (const int connfd);
static inline int zhou_online	 (const int connfd);
static inline void zhou_interface(const int messtype, char *mess, int messlen);

//给定接口进行聊天
int zhou_chat(const int connfd) {
	int ret;
	//初始聊天进行对方状态确认:-1：出错， 0：对方不在线，1:对方在线 
	ret = zhou_get_status(connfd);
	switch(ret) {
		case -1: return -1;

		case 1:
			ret = zhou_online(connfd);
			if (ret == -1) return -1;
			else if (ret == 0)
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
	char   buf[100], label;
	int    signsend, signrev;

	fds[0].fd 	   = connfd;
	fds[1].fd 	   = connfd;
	fds[0].events  = POLLIN;
	fds[1].events  = POLLOUT;
	fds[0].revents = 0;
	fds[1].revents = 0;

	memset(buf, 0, 100);
	len_l = strlen(myname);
	len_d = strlen(desthost);
	memcpy(buf, myname, len_l);
	memcpy(buf+len_l+1, desthost, len_d);
	buf[len_l] = '#';

	while (signrev <= 0) {
		ret = poll(fds, fdnum, timeout);
		if (ret == -1) {
			perror("poll");
			return -1;
		}
	
		if (fds[1].revents == POLLOUT)
			signsend = write(connfd, buf, 100);
	
		if (signsend > 0 || fds[0].revents == POLLIN) {
			signrev = read(connfd, label, 1);
			if (signrev > 0) break;
	}
	return signrec;
}

//输入：连接端口	输出：根据端口进行聊天
static inline int zhou_online(const int connfd) {
	struct pollfd fds[3];
	int fdnum = 3, timeout = 20, ret;
	char buf_send[BUF_SEND_CAP], buf_recv[BUF_RECV_CAP];

	fds[0].fd 	  = connfd;
	fds[1].fd 	  = connfd;
	fds[0].events = POLLIN;
	fds[1].events = POLLOUT;
	fds[2].fd	  = STDIN_FILENO;
	fds[2].events = POLLIN;
	
	while(1) {
		ret = poll(fds, fdnum, timeout);
		if (ret == -1) {
			perror("poll");
			return -1;
		}
		if (fds[2].revents == POLLIN && fds[1].revents == POLLOUT) {
			ret = read(STDIN_FILENO, buf_send, BUF_SEND_CAP);
			switch (ret) {
				case 0:
					return 0;
					break;
				case -1:
					perror("read messege");
					return -1;
					break;
				default:
					write(connfd, buf_send, ret);
					break;
			}
		}
	//被动接受信息
		if (fds[0].revents == POLLIN) {
			ret = read(connfd, buf_recv, BUF_RECV_CAP);
			if (ret == -1)
				return -1;
			else if (ret == 0) break;
			ret = zhou_interface(1, buf_recv, BUF_RECV_CAP);
			if (ret == -1)
				return -1;
			bzero(buf_recv, BUF_RECV_CAP);
		}
	}
	return 0;
}

//输入：端口fd	输出：聊天
static inline int zhou_nonline(const int connfd) {
	//实际上和在线聊天的形式类似
	char feedback[] = "对方不在线，可对其留言";
	int  ret, feedlen = strlen(feedback);;

	ret = zhou_interface(0, feedback, feedlen);
	if (ret == -1) return -1;
	
	ret = zhou_online(connfd);
	if (ret == -1) return -1;
	return 0;
}
	
//界面信息消息显示
static inline void zhou_interface(const int messtype, 
			char *mess, int messlen) {
	switch (messtype) {
		case 2:
			zhou_baseface();
			break;
		case 1:
			zhou_message_print(me, mess, messlen);
			break;
		case 0:
			zhou_message_print(other mess, messlen);
			break;
		default:
	}
}
//TODO 编写基础界面
void zhou_baseface(const int posi) {
	switch (posi) {
		case 0:
		case 1:
			system("clear");
 			for (int i = 0; i < 30; i++) {
				for (int j = 0; j < 150; j++) {
					if ( i == 0 || i == 29)
						printf("*");
					else {
						if (j == 0 || j == 149) {
							printf("*");
						}
						else {
							if (i == 25 && j > 0 && j < 149)
								printf("-");
							else printf("\033[1C");
						}
					}
				}
				printf("\n");
			}
			printf("\033[149A\033[1C");
			break;
		//TODO 
		case 2:

		case -1:

		

}
	
}
//TODO 编写聊天界面
static inline void zhou_message_print(const int messfrom,
			const char *message, const int messlen) {
	
	
}
*/


