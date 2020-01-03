#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdlib>


using namespace std;

class Soln
{
	public:

	int MinSubsetSumDifference(vector<int> vecNums)
	{
		//calculate possibility of subset sum upto S/2
		//S/2 is best as it gives 0 difference

		int nSum= 0;
		for(auto & num :vecNums) nSum += num;
		int nTarget = nSum/2;

		vector<bool> vecSubs(nTarget+1,false);

		//init for first value
		for(int i = 0; i<vecSubs.size(); i++)
			vecSubs[i] = (i==vecNums.front() || i==0);

		//biuld bottom up for rest
		int maxCapSoFar = INT_MIN;

		for(int i =1; i<vecNums.size(); i++)
		{
			//reverse
			for(int t = vecSubs.size()-1; t>=0; t--)
			{
				bool isIncluded = (t<vecNums[i])? false : vecSubs[t-vecNums[i]];

				vecSubs[t] = vecSubs[t] || isIncluded;

				if (vecSubs[t] && t>maxCapSoFar) maxCapSoFar = t;
			}
		}

		return abs(maxCapSoFar-(nSum-maxCapSoFar));

	}
};


int main()
{
	vector<int> vecNums = {1,2,3,9};

	printf("Min Subset sum difference is %d\n", Soln().MinSubsetSumDifference(vecNums));

	return 0;
}

