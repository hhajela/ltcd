#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>


// inputs = weights, profits, capacity
// return the chosen items
//
using namespace std;

class Soln
{

	int ** dp;
	int counter = 0;

	public:

int BottomUpKnapsack(vector<int> weights, vector<int> profits, int capacity)
{
	//we just need one row
	//fill and initialize dp array with -1
	int * dp = new int [capacity+1];
	fill_n(dp,capacity+1,0);

	//dp[c] will represent the max profit that can be made by considering 0..i items for c capacity
	
	//init the row with appropriate values for i = 0
	//only 1 item considered, profit = profit of item if it can be included or not
	for(int c = 0; c<=capacity; c++)
		dp[c] = c>=weights.front()?profits.front():0;

	//populate the rest of the entries using relation
	//if you arrived at dp[i][c] by making a decision to include item i then dp[i][c] = dp[i-1][c-weight[i]]+profit[i]
	//otherwise you arrived by excluding ith item, then dp[i][c] = dp[i-1][c]
	//best choice is what gets more profit

	for(int i =1; i<weights.size(); i++)
	{
		//iterate in reverse so we can use previously computed values without overwriting them
		for(int c=capacity; c>=0; c--)
		{
			if (c==0) //cap zero means you cant include anything
				dp[c] = 0;
			else
			{
				//non zero capacity, use prev computed values

				int profit1 = dp[c]; //didnt include ith item, profit same as was uptil i-1
				
				// included ith item so profit = profit from ith + max profit that was got from a c-weight size knapsack
				// with only uptil i items considered
				int profit2 = c >= weights[i]? (dp[c-weights[i]]+profits[i]) : 0;

				//overwrite value with the higher number
				dp[c] = max(profit1,profit2);
			}
		}
	}

	
	for(int j =0; j<=capacity; j++)
	{
		printf("%d ",dp[j]);
	}
	printf("\n");

	//PrintIncludedKnapsackItems(weights,capacity);

	return dp[capacity];
}

void PrintIncludedKnapsackItems(vector<int> & weights, int capacity)
{
	//iterate thru the dp array, print items that are included
	//item i is included if dp[i][c] not equal to dp[i-1][c]
	

	int i = weights.size()-1;
	int c = capacity;
	printf("included items :- \n");
	while(dp[i][c] > 0)
	{
		if (i==0)
		{
			//only considering first item
			printf("%d ", i);	
			return;
		}
		else if (dp[i][c] == dp[i-1][c])
			i--; //item skipped
		else
		{
			//item was included 
			printf("%d ", i);
			c -= weights[i];
			i--;
		}
	}
	cout << endl;
	return;
}

set<int> KnapsackSolver(vector<int> weights, vector<int> profits, int capacity)
{
	dp = new int*[weights.size()];
	for (int i=0; i<weights.size(); i++)
	{
		dp[i] = new int[capacity]{-1};

		fill_n(dp[i],capacity,-1);
	}

	set<int> setResult;
	int maxProfit = RecursiveKnapsackChooser(weights,profits,capacity,setResult);
	printf("max profit %d\n", maxProfit);
	printf("number of calls %d\n", counter);
	return setResult;
}

int RecursiveKnapsackChooser(vector<int> weights, vector<int> profits, int capacity, set<int> & setResult, int currentIndex=0)
{
	//either pick or skip this item, return maximum profit of these two options
	
	if (currentIndex >= weights.size()) return 0;
	printf("Current index, capacity [%d,%d] ",currentIndex,capacity);
	if (dp[currentIndex][capacity-1] != -1)
	{
		printf("Seen this before\n");
		return dp[currentIndex][capacity-1];
	}

	counter++;
	
	int profit1 = (weights[currentIndex]>capacity)?0:(profits[currentIndex]+RecursiveKnapsackChooser(weights,profits,capacity-weights[currentIndex],setResult,currentIndex+1));

	int profit2 = RecursiveKnapsackChooser(weights,profits,capacity,setResult,currentIndex+1);

	int maxProfit = max(profit1,profit2);
	dp[currentIndex][capacity-1] =  maxProfit;

	printf("Current max profit %d \n", maxProfit);

	if (maxProfit == profit1)
		setResult.insert(currentIndex);

	return maxProfit;
		
}

};


int main()
{
	vector<int> weights = {1,2,3,5};
	vector<int> profits= {1,6,10,16};

	Soln S1;
	/*
	set<int> setIncluded =  S1.KnapsackSolver(weights,profits,7);

	printf("included weights \n");

	for(auto & index: setIncluded)
		printf("%d ", weights[index]);

	printf("\n");
	*/
	printf("max profit %d ", S1.BottomUpKnapsack(weights,profits,7));

	return 0;
}
