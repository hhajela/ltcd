#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>


using namespace std;


int MaxLootRecursive(const vector<int>& vecHouses, int nCurInd = 0)
{
	if(nCurInd>vecHouses.size()-1) return 0;

	//if (nCurInd == vecHouses.size()-1) return vecHouses.back();

	//if (nCurInd == vecHouses.size()-2) return max(vecHouses[nCurInd],vecHouses[nCurInd+1]);

	//you either pick the current one, then skip the next and compute recursively on the rest
	//or you skip the current one, decide what you want to do with the second recursively 
	return max(vecHouses[nCurInd] + MaxLootRecursive(vecHouses, nCurInd+2), MaxLootRecursive(vecHouses,nCurInd+1));
}

int MaxLootIterative(const vector<int> & vecHouses)
{
	//start from the end
	//basic cases
	if(vecHouses.size()==1) return vecHouses.back();


	//for last one value is predecided
	int nPlusTwo = vecHouses.back(); //max loot 
	int nPlusOne = max(vecHouses[vecHouses.size()-2],vecHouses.back()); //max loot = choice between this and the next

	//calculate for the remaining
	for(int i = vecHouses.size()-3; i>=0; i--)
	{
		//one way = pick this, skip next, process remaining
		//other -skip this, process remaining
		//pick bigger one
		int temp = max(nPlusOne, vecHouses[i]+nPlusTwo);
		nPlusTwo = nPlusOne;
		nPlusOne = temp;
	}
	return nPlusTwo;
}

int MaxLootIterative2(const vector<int> & vecHouses)
{
	//basic case
	if (vecHouses.size()==1) return vecHouses.front();

	if(vecHouses.size()==2) return max(vecHouses[0],vecHouses[1]);

	//populate initial values i.e. max loot for first and first 2 houses
	int nMinusOne = max(vecHouses[0],vecHouses[1]);
	int nMinusTwo = vecHouses[0];

	//populate from three onward
	for(int i=2; i<vecHouses.size(); i++)
	{
		//if this house was picked you came from i-2 or earlier
		//if this house was skipped you came from i-1 or earlier
		int temp = max(nMinusOne,vecHouses[i]+nMinusTwo);

		nMinusTwo = nMinusOne;
		nMinusOne = temp;
	}
	return nMinusOne;
}


int main()
{
	vector<int> vecHouses = {2,5,1,3,6,2,4};

	printf("max loot : %d\n",MaxLootIterative2(vecHouses));
	return 0;
}
