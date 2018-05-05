#include <stdio.h>
#include <iostream>
using namespace std;

int CalculateSum(unsigned int nNum)
{
	int nFactor = 10;
	int nSum = 0;
	while (nNum > 0)
	{
		nSum += nNum % nFactor;
		nNum /= nFactor;
	}
	return nSum;
}

bool check_result(unsigned int nNum)
{
	bool bMagic = false;
	// this number should be big than 10
	if (nNum < 10)
	{
		return false;
	}
	
	unsigned int tmp = nNum;
	int nFactor = 10;		// Factor begin with 10. xxxx|x
	while (nFactor < nNum)
	{
		int nRightNum = tmp % nFactor;	// the nNum is departed by '|' from nRightNum and nLeftNum. 
		int nLeftNum = tmp / nFactor;

		int nRightSum = CalculateSum(nRightNum);
		int nLeftSum = CalculateSum(nLeftNum);
		
		// if two sum are equal,then the nNum is a magic number.
		if (nRightSum == nLeftSum)
		{
			bMagic = true;
			break;
		}
		
		// move the Factor to the left. 
		nFactor *= 10;
	}
	return bMagic;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int nNum = 0;
		cin	>> nNum;
		bool bMagic = check_result(nNum);
		cout<<bMagic<<endl;
	}
	return 0;
}