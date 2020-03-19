#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int LBS(const vector<int> & vecNums)
{
	//calculate longest decreasign and increasing sequence for every index, reuse values
	//take sum of lds and lis on both sides of each index, keep track of max
	
	if (vecNums.empty()) return 0;

	int nMax=1; //lbs of 1 is possible
	vector<int> vecLDS(vecNums.size(),1); //all numbers a 1 sized lds in themselves
	vector<int> vecLIS(vecNums.size(),1); //""

	for (int i =0; i<vecNums.size(); i++)
	{
		for(int j = 0; j<i; j++)
		{
			//pick if better than current and satisifes constraints
			if (vecNums[i]>=vecNums[j] && vecLIS[j]+1>vecLIS[i])
			{
				vecLIS[i] = vecLIS[j] +1;
			}

		}
	}

	for(int i =vecNums.size()-1; i>=0; i--)
	{
		for(int j =i+1; j<vecNums.size(); j++)
		{
			//pick if better than current choice and satisfies constraints
			if(vecNums[i]>=vecNums[j] && vecLDS[j]+1>vecLDS[i])
				vecLDS[i] = vecLDS[j]+1;
		}

		if (vecLDS[i]+vecLIS[i]-1> nMax) //-1 since ith is counted twice
			nMax = vecLDS[i]+vecLIS[i]-1;
	}

	return nMax;

	
}


int main(int argc, char ** argv)
{
	vector<int> vecNums;
	int nLength = 0;

	cin >> nLength;


	vecNums = vector<int>(nLength);

	for(int i =0; i<nLength; i++)
		cin >> vecNums[i];

	printf("length of lbs is %d", LBS(vecNums));
	return 0;
	
}
