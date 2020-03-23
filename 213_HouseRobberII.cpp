#include <iostream>
#include <vector>

using namespace std;

int MaxRingLoot(const vector<int>& nums)
{
	//take maximum of loot from 0 to n-2 and 1 to n-1
	
	//case where 0 is picked

	int lootMinusTwo =0;
	int lootMinusOne =nums.front();

	for(int i =1; i<nums.size()-1; i++)
	{
		int bestLoot = max(nums[i]+lootMinusTwo,lootMinusOne);
		lootMinusTwo = lootMinusOne;
		lootMinusOne = bestLoot;
	}

	int bestLoot = lootMinusOne;


	//case where 0 is skipped
	lootMinusOne = nums[1];
	lootMinusTwo = 0;

	for(int i = 2; i<nums.size(); i++)
	{
		int best = max(nums[i]+lootMinusTwo,lootMinusOne);
		lootMinusTwo = lootMinusOne;
		lootMinusOne = best;
	}

	bestLoot = max(bestLoot,lootMinusOne);
	
	return bestLoot;

}

int main()
{
	int nLength;
	cin >> nLength;

	vector<int> vecHouses(nLength);

	for(int i =0; i<vecHouses.size(); i++)
		cin >> vecHouses[i];

	cout << "Max ring loot is " << MaxRingLoot(vecHouses) << endl;
	return 0;

}
