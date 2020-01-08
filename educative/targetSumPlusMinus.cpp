#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Soln
{
	public:

	int TargetSumPlusMinus(vector<int> vecNums, int nTarget)
	{
		//add or subtract
		return RecursiveTargetPlusMinus(vecNums, nTarget);
	}

	int RecursiveTargetPlusMinus(const vector<int> & vecNums, int nTarget, int nCurInd = 0, int nCurSum = 0)
	{
		//base case, fi you reached the last, check if this value can make the target
		if (nCurInd == vecNums.size()-1)
			if (nTarget == nCurSum + vecNums[nCurInd] || nTarget == nCurSum -vecNums[nCurInd])
				return 1;
			else 
				return 0;

		//else return the number of ways to get to target for both + and - cases
		return RecursiveTargetPlusMinus(vecNums, nTarget, nCurInd+1, nCurSum+vecNums[nCurInd]) + RecursiveTargetPlusMinus(vecNums, nTarget, nCurInd+1, nCurSum-vecNums[nCurInd]);
	}

	int TargetSumPlusMinsCount(const vector<int> & vecNums, int nTargetDiff)
	{
		//need to divide vecNums into two sets, add and subtract
		//add = all numbers with + prefixed
		//sub  = all numbers with - prefixed
		//sum = add + sub
		//target = add-sub
		//add = (sum+target)/2
		//sub  = sum- (sum+target)/2
		

		//so problem is to find set of size s-(s+t)/2
		
		//calculate sum
		int nSum = 0;
		for (auto & num:vecNums) nSum += num;
		
		//desired target
		int nTargetSum = nSum-(nSum+nTargetDiff)/2;

		//number of ways of making a sum of that size
		vector<int> vecSubs(nTargetSum+1,0);
				
		//initialize for basic first number
		for (int i = 0; i<vecSubs.size(); i++)
			vecSubs[i] = (i==0 || i== vecNums.front())?1:0;

		//build bottom up for rest
		for (int i = 1; i<vecNums.front(); i++)
		{
			//iterate in reverse
			for(int t= vecSubs.size()-1; t>=0; t--)
			{
				//if for this index we included this number
				//then number of ways equals number of ways for target - the current idnex w
				//as long as this weight was less than the target
				int nIncluded = t<vecNums[i]?0:vecSubs[t-vecNums[i]];

				//if it was skipped, then no of ways = no of ways for sametarget
				//but for previous indices
				vecSubs[t] += nIncluded;
			}
		}

		//the last one is the number of ways for the target sum
		return vecSubs.back();
		
	}
};

int main()
{
	vector<int> vecNums {1,1,2,3};
	int nSum = 1;

	printf("number of ways of in4erting + and - to make %d is %d\n", nSum, Soln().TargetSumPlusMinus(vecNums,nSum));
	return 0;
}
