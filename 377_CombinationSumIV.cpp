#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

int CombinationsSum(const vector<int> & vecNums, int target)
{
	if (vecNums.empty()) return 0;

	//keep track of number of ways for each value <=target
	vector<int> vecSubs(target+1,0);

	//no of ways to reach target 0 =1 (dont include anything)
	vecSubs[0] =1;

	//for all possible target values <= target
	//number of ways equals number of ways obtained from includign or skipping given numbers
	for(int t =1; t<vecSubs.size(); t++)
	{
		for (int j =0; j<vecNums.size(); j++)
		{
			vecSubs[t] += (t>=vecNums[j]? vecSubs[t-vecNums[j]] : 0);
		}
	}

	return vecSubs.back();
}


int main()
{
	int target;
	cin >> target;
	
	int length;
	cin >> length;

	vector<int> vecNums(length);
	for(int i=0; i<vecNums.size(); i++)
		cin >> vecNums[i];

	cout << "Combination sum is " << CombinationsSum(vecNums,target);	
	return 0;
}
