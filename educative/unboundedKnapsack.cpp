#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int UnboundedKnapsack(vector<int> vecW, vector<int> vecP, int nCap)
{
	//build values bottom up
	
	//subsolutions is going to keep track of max profit for all capacities for all indices
	vector<vector<int>> vecSubSolutions(vecW.size(), vector<int>(nCap+1,0));

	//init max profit for first item
	for(int i= 0; i<=nCap; i++)
		vecSubSolutions[0][i] = (i<vecW.front())? 0 : (i/vecW.front() * vecP.front());

	//build rest
	for(int i=1; i<vecSubSolutions.size(); i++)
	{
		for(int t=0; t<vecSubSolutions[i].size(); t++)
		{
			//either we included this
			int nProfitIncluded = (t<vecW[i])? 0: vecP[i] + vecSubSolutions[i][t-vecW[i]];

			//we skipped it then profit same as before
			int nProfitSkipped = vecSubSolutions[i-1][t];

			vecSubSolutions[i][t] = max(nProfitIncluded,nProfitSkipped);
		}
	}

	return vecSubSolutions.back().back(); //last element corresponds to max profit for all items considered for nCap
}


int main()
{
	vector<int> vecNums = {1,2,3};
	vector<int> vecP = {15,20,50};

	printf("max possible profit is %d\n", UnboundedKnapsack(vecNums, vecP, 5));

	return 0;

}
