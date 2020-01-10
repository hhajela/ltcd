#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;


int CountClimbingStairs(int nLength)
{
	//number of ways to get to step n = number of ways to get to step n-1,n-2,n-3


	//number of ways for 1,2,3 stairs are trivial
	int nMinusThree = 1;
	int nMinusTwo = 2;
	int nMinusOne =4;

	if(nLength==3)
		return nMinusOne;
	else if (nLength==2)
		return nMinusTwo;
	else if (nLength==1)
		return nMinusThree;

	int cur = 0;
	for(int i = 4; i<=nLength; i++)
	{
		cur = nMinusThree + nMinusTwo + nMinusOne; //current = current - 1 + current -2 + current -3

		nMinusThree = nMinusTwo;
		nMinusTwo = nMinusOne;
		nMinusOne = cur;
	}

	return cur;
}


int main(int argc, char ** argv)
{
	int nLength = (argc>1)?atoi(argv[1]):5;
	printf("Number of ways of climbing %d stairs is %d\n",nLength, CountClimbingStairs(nLength));

	return 0;
}
