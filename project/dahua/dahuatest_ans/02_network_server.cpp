/* 试题描述
 * 网络上有一台流媒体服务器S和一台客户端C，S向C发送流媒体数据。
 * 1、S的发送速率为M；
 * 2、C有一个缓冲区B，最大值大小为X，B接收来自S的流媒体，C处理B中的数据并清理，B的处理速度为N。
 * 3、为保证C处理的效率，当缓冲区大小超过80%时，C发送停止命令给S，S将停止向C发送数据。
 * 4、当缓冲区大小小于60%时，C向S发送重启发送数据命令，S向C发送数据。
 * 5、题中所有单位都是基本单位。
 * 请设计一个函数handle_data_func，用来处理缓冲区B，并计算C第一次向S发送重启发送数据命令的时间T0及每次发送重启命令的的时间间隔T1。
 */
#include<iostream>
#include<stdio.h>
using namespace std;

double handle_data_func(double M,double N,double X,double &T1)
{
	double T0 = 0;
	double nSpeed = M-N;					// 发送速度减去接收速度为客户端的累积速度。
	T0 = 0.8*X / nSpeed + 0.2*X / N;	
	T1 = 0.2*X/nSpeed + 0.2*X/N;
	return T0;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		double M,N,X;
		double T0,T1 = 0;
		cin>>M>>N>>X;

		T0 = handle_data_func(M, N, X, T1);
		if (T0 <= 0)
		{
			cout<<"You must input some wrong parameters"<<endl;
		}
		else
		{
			printf("%.2f\n", T0);
			printf("%.2f\n", T1);
		}
	}
	return 0;
}
