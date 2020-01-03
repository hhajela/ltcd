#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>


using namespace std;

class Soln
{
	int nCounter= 0; 
	int ** dp;
	public:

bool IsEqualSubsetSum(vector<int> vecNums)
{
	//recursive solution brute force
	
	int sum = 0;
	for(auto & num: vecNums) sum+= num;

	//need to pick elements that can make the sum s/2
	bool isEqual =  RecursiveEqualSubsetSum(vecNums, sum/2);
	cout << "number of calls = " << nCounter << endl;
	return isEqual;
}

bool TopDownESS(vector<int> vecNums)
{
	//whether currentindex=i and target = t has a sln or not
	//depends on i+1,t and i+1,t-currentvalue having a sln or not
	
	int nSum = 0;
	for (auto & num: vecNums) nSum += num;

	if (nSum%2 != 0) return false;
	
	dp = new int * [vecNums.size()];
	for (int i=0; i<vecNums.size(); i++)
	{
		dp[i] = new int[nSum/2];
		fill_n(dp[i], nSum/2, -1);
		cout << dp[i][0];
	}

	return RecursiveESS2(vecNums, nSum/2);
}

bool RecursiveESS2(vector<int> vecNums, int nTarget, int nCurIndex=0)
{
	if (nCurIndex > vecNums.size()-1) return false;

	if (dp[nCurIndex][nTarget-1] != -1)
	{
		printf("already calculated");
		return static_cast<bool>(dp[nCurIndex][nTarget]);
	}
	//base case
	printf("Calculating for index %d, target %d --- ", nCurIndex, nTarget);
	if (nTarget == vecNums[nCurIndex])
	{
		dp[nCurIndex][nTarget] = 1;
		printf("\n");
		return true;
	}
	else
	{
		//recurse with either this oen skipped or included
		bool wayOne = vecNums[nCurIndex]>nTarget? false :RecursiveESS2(vecNums,nTarget-vecNums[nCurIndex],nCurIndex+1);
		bool wayTwo = RecursiveESS2(vecNums,nTarget,nCurIndex+1);

		dp[nCurIndex][nTarget] = (wayOne||wayTwo)?1:0;
		printf("\n");
		return wayOne || wayTwo;
	}
	printf("\n");

	return false;
}

bool BottomUpESS(vector<int> vecNums)
{
	//find numbers that can sum up to Sum/2
	int nSum = 0;
	for(auto & num: vecNums) nSum += num;

	if(nSum%2 != 0) return false; //odd sum means sum/2 cannot be equal

	vector<int> vecSubs(nSum/2+1, -1); //vector of sub solutions

	//init for first value
	for(int i = 0; i<vecSubs.size(); i++)
		vecSubs[i] = i == vecNums.front()? 1:0; // possible if the value equals te target

	for(int i = 1; i<vecNums.size(); i++)
	{
		//iterate in reverse so we dont overwrite old values
		for(int t= vecSubs.size()-1; t>=0; t--)
		{
			//one possibility, we didnt include this for the target
			//then this is a possible solution if it was a valid soln for prev ind and target
			bool oneWay = vecSubs[t];

			//second possibility, we included this, then it is possible
			//if solution for previous index and target-current was possible
			bool twoWay = vecNums[i] <t ? vecSubs[t-vecNums[i]] : false;

			vecSubs[t] = static_cast<int>(oneWay || twoWay);
		}
	}

	return static_cast<bool>(vecSubs.back());
}


bool RecursiveEqualSubsetSum(vector<int> vecNums, int nTarget, int nCurIndex=0)
{
	if (nCurIndex > vecNums.size()-1) return false;

	//see if any of the two option return a choice where you sum up to target
	
	nCounter++;
	
	//base case, element considered is target
	if (vecNums[nCurIndex] == nTarget)
		return true;
	else if (RecursiveEqualSubsetSum(vecNums, nTarget-vecNums[nCurIndex],nCurIndex+1) || RecursiveEqualSubsetSum(vecNums, nTarget,nCurIndex+1))
		return true; // either skipping or choosing results in total sum target
	else
		return false;
}

};



int main()
{
	vector<int> vecNums {2,3,4,6};
	printf("vecNums has equal sum subsets = %s\n", Soln().BottomUpESS(vecNums)?"true":"false");
	return 0;
}
