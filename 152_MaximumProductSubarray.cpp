#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>


using namespace std;

int GetMaximumProductSubarray(vector<int> vecNums)
{
	//modified kadane's
	
	int bestProd = vecNums[0];
	int maxCurProd = vecNums[0];
	int minCurProd= vecNums[0];

	for(int i = 1; i<vecNums.size(); i++)
	{
		int tempMaxCur = maxCurProd;
		maxCurProd = max(vecNums[i],max(maxCurProd*vecNums[i],minCurProd*vecNums[i]));

		minCurProd = min(vecNums[i],min(tempMaxCur*vecNums[i],minCurProd*vecNums[i]));

		bestProd = max(bestProd,maxCurProd);
	}

	return bestProd;
}


int main()
{
	vector<int> vecOne = {1,3,-4,-1,12,-1,-2};

	printf("The maximum product for subarray is %d", GetMaximumProductSubarray(vecOne));
	return 0;
}

