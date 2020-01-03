#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

class Soln
{
	public:

	bool IsTargetSumSubsetPresent(const vector<int> & vecNums, int nTarget)
	{
		//if target greater than total sum then not possible
		int nSum = 0;
		for(auto & num: vecNums) nSum += num;
		if (nSum < nTarget) return false;

		//vector of subsolutions
		vector<bool> vecSubs(nTarget+1,false);

		//init for first value
		for(int i= 0; i<vecSubs.size(); i++)
			vecSubs[i] = (i == vecNums.front() || i==0 );//possible to reach target zero always(dont include the value)

		//calculate bottom up for other values
		for(int i = 1; i<vecNums.size(); i++)
		{
			//iterate in reverse so you dont overwrite values
			for(int t = vecSubs.size()-1; t>=0; t--)
			{
				//either we didnt include this value
				//then target possible if it was i-1
				bool option1 = vecSubs[t];

				//other option is we did include this number
				//then target possible if target-current was possible for i-1
				bool option2 = t < vecNums[i] ? false : vecSubs[t-vecNums[i]];

				vecSubs[t] = (option1 || option2);
			}
		}
		return vecSubs.back();
	}

};

int main()
{
	vector<int> vecNums = {11,1,1,3,4,7};
	int nTarget = 10;

	printf("vecNums %s contain subset with sum %d\n", Soln().IsTargetSumSubsetPresent(vecNums,nTarget)?"does":"doesnt", nTarget);
	return 0;
}
