#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

int BestTimeToBuyAndSellStock(vector<int> vecPrices)
{
	int maxProfit = 0;
	int minPrice = INT_MAX;

	//  1 3 2 7 4 11 5
	
	for(auto & price : vecPrices)
	{
		if (price < minPrice)
			minPrice = price;
		else
			maxProfit = max(maxProfit,price-minPrice);
	}

	return maxProfit;
}

int main()
{
	vector<int> prices = {3,4,7,2,8};
	cout << "max profit is " << BestTimeToBuyAndSellStock(prices) << endl;

	return 0;}
