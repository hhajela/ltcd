#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>


using namespace std;

int MinFeeJumpEnd(vector<int> vecFee)
{
	//we can get to the nth step from n-1, n-2 and n-3
	//min fee is min of the fee for these steps plus fee till that point
	
	//basic cases
	if(vecFee.size()<4) return vecFee.front(); //you can always jump 1/2/3 steps so in this case min fee is the first step fee

	//calculate initial values for stairs 3,2 and 1
	int nMinusOne = vecFee[0]; //fee for the third preceding or n minus one value
	int nMinusTwo = vecFee[0]; //fee for second preceding or n minus two value
	int nMinusThree = 0; //fee for the first preceding or n minus three value

	int cur;
	//calculate for rest uptil beyond last
	for(int i=3; i<=vecFee.size(); i++)
	{
		//min is min of preceding three + associated fee
		cur = min(nMinusOne+vecFee[i-1],min(nMinusTwo+vecFee[i-2],nMinusThree+vecFee[i-3]));
		nMinusThree= nMinusTwo;
		nMinusTwo= nMinusOne;
		nMinusOne = cur;

		//cout << nMinusOne << " " << nMinusTwo << " " nMinusThree << endl;
	}
	return cur;
}


int main()
{
	vector<int> vecFee = {1,2,5,2,1,2};
	printf("Min fee to get to end is %d\n",MinFeeJumpEnd(vecFee));
	return 0;
}
