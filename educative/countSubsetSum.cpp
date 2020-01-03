#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>


using namespace std;


class Soln
{
	public:

	int CountSubsetSum(vector<int> vecNums, int nTarget)
	{
		//do same procedure as for target sum subset
		//ut keep track of number of subsets with sum <=target
		vector<int> vecSubs(nTarget+1,0);

		//init first row
		for(int i=0; i<vecSubs.size(); i++)
			vecSubs[i] = (vecNums.front()==i || i==0) ? 1 :0;

		//build rest solutions bottom up
		for(int i =1; i<vecNums.size(); i++)
		{
			//reverse
			for(int t = vecSubs.size()-1; t>=0; t--)
			{
				//first possibiltiy this number is included
				//then number of ways of reaching here is same as number of ways of reaching
				//target-current number for prev index
				int nFirstBranch = t<vecNums[i]? 0 : vecSubs[t-vecNums[i]];

				//second possiblity is the number was not included
				//then number of wasy same as number of ways of reaching target for prev index
				//add both to get total possiblities for current target and ucrrent index

				vecSubs[t] += nFirstBranch; //update value
			}
		}

		return vecSubs.back(); //corresponds to target and all indices considered
	}
};

int main()
{
	vector<int> vecNums = {1,2,7,1,5};
	int nTarget = 9;
	printf("The number of subsets wiht sum %d is %d \n", nTarget, Soln().CountSubsetSum(vecNums,nTarget));
}
