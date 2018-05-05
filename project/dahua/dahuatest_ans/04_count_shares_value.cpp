﻿/* 算法概述	
 * 股票种类n,股价v[i],股票数量m[i]；
 * v1 v2 v3 v4 .... vn
 * m1 m2 m3 m4 .... mn
 * 假设前i种股票能套现出不同资金量的数目为Q[i]，那么Q[i]可以这么计算：在Q[i-1]的基础上，对Q[i-1]套现资金基础上，分别卖出k股i类型股票，在卖出过程中去重。
 * Q[i] = Q[i-1]+k*v[i]-卖出中重复的个数，其中0<=k<=m[i]
 */
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;	//股票种类数
		cin>>n;
		int *v = new int [n]; //每种股票的股价 
		int *m = new int [n]; //每种股票的股数
		for (int i=0; i<n; i++)
		{
			cin >> v[i];
		}
		for (int i=0; i<n; i++)
		{
			cin >> m[i];
		}

		vector<int>money; //所有卖出股票的资金量
		/*先将第一种股票所卖出的资金数入列*/
		money.push_back(0);
		for (int i=1;i<=m[0];i++)
		{
            if(i * v[0] != 0)
            {
                money.push_back(i*v[0]);
            }
		}
		//前多少种股票
		for (int i=1;i<n;i++)
		{
			int len = money.size();//记录已经卖出的资金量数
			for (int j=1;j<=m[i];j++) //遍历该股票的股数
			{
				for (int z=0;z<len;z++)
				{
					int moneyTmp = money[z] + j*v[i];//将该股票的抛售的资金与前面所有的资金数相加
					if (find(money.begin(), money.end(), moneyTmp) == money.end())//如果没有这个资金数则将这个资金入列
					{
						money.push_back(money[z]+j*v[i]);
					}
				}
			}
		}
		cout << money.size() << endl;
	}

	return 0;
}
