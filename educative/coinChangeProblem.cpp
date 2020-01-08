#include <vector>
#include <climits>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int MinCoinChange(vector<int> vecDenom, int nTarget)
{
	//knapsack problem
	
	//can include each coin 0 or more times as long as capacity is not exceeded
	//cost associated is 1 with each coin
	//need to minimize the cost
	
	//lookup values have minimum cost for each coin for different target amounts uptil target
	vector<vector<int>> vecSubs(vecDenom.size(), vector<int>(nTarget+1,INT_MAX));

	//init for first value for all capacities
	for(int t = 0; t<=nTarget; t++)
		vecSubs[0][t] = (t%vecDenom.front()==0)? (t/vecDenom.front()):INT_MAX; //cost is number of coins if divisible else infinity

	//build rest
	for(int i =1; i<vecSubs.size(); i++)
	{
		for(int t =0; t<vecSubs[i].size(); t++)
		{
			//if this coin was included this time, then cost = 1 for this coin + cost for remaining amount
			//remaining = current - this coin value
			int nCostIncluded = (t<vecDenom[i]) ? INT_MAX : ( vecSubs[i][t-vecDenom[i]]== INT_MAX)?INT_MAX: vecSubs[i][t-vecDenom[i]]+1;
			
			//if coin skipped, then cost same as cost for earlier coins for the same amount
			int nCostSkipped = vecSubs[i-1][t];

			vecSubs[i][t] = min(nCostIncluded,nCostSkipped); //choose lower
		}
	}

	for (int i =0; i<vecSubs.size(); i++)
	{
		for(int t = 0; t<vecSubs[i].size(); t++)
			cout << vecSubs[i][t] << " ";
		cout << endl;
	}

	return vecSubs.back().back(); //return the lowest cost for considering all items to build change for amount nTarget
}

int main()
{
	vector<int> vecDenom = {4,2,6};
	int nTarget = 13;

	int nWays= MinCoinChange(vecDenom,nTarget);
	nWays = nWays==INT_MAX?-1:nWays;

	printf("min number of coins to make chagne for %d is %d\n", nTarget, nWays);
}
