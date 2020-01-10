#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int MaxProfitRodCutting(vector<int> vecPrices)
{
	//the prices are like choices of items
	
	//maintain a vector of max profit for all possible lengths for different rod lenghts
	vector<vector<int>> vecSubs(vecPrices.size(), vector<int>(vecPrices.size()+1,0));

	//init for first lenght(1)
	for(int i=0; i<=vecPrices.size(); i++)
		vecSubs[0][i] = i*vecPrices.front(); //since first length is 1, profit = total length * profit for length 1

	//build rest of the values
	for(int i =1; i<vecSubs.size();i++)
	{
		for(int t=0; t<vecSubs[i].size(); t++)
		{
			//either we included this length
			//then max profit is profit from this plus max profit from remaining length
			int nProfitIncluded = (t< (i+1))?0: vecPrices[i]+vecSubs[i][t-(i+1)];

			//profit skipped is same as profti for previous lenght for same total lenght
			int nProfitSkipped = vecSubs[i-1][t];

			vecSubs[i][t] = max(nProfitIncluded,nProfitSkipped);

		}
	}

	return vecSubs.back().back();
}

int main()
{
	vector<int> vecPrices = {2,6,7,10,13};

	printf("max proft is %d \n", MaxProfitRodCutting(vecPrices));

	return 0;
}
