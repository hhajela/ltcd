#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

class Solution
{
	public:

		bool ContainsNearbyDupes(const vector<int> & vecNums, int k)
		{
			//loop thru the numbers
			unordered_map<int,int> mapIndices;

			for (int i=0; i<vecNums.size(); i++)
			{
				//check if youve seen this number before, if not then add to map
				if (mapIndices.find(vecNums[i]) == mapIndices.end())
					mapIndices[vecNums[i]] = i;
				else	//if yes then check difference in indices
				{
					if (abs(mapIndices[vecNums[i]] - i) <= k)	
						return true;//if close then return true
					else
						mapIndices[vecNums[i]] = i; //else update the last seen index for this number

				}

			}

			return false;
			
		}
};


int main()
{
	int size;
	cin >> size;

	int k;
	cin >> k;

	vector<int> vecNums(size,0);
	for (int i=0; i<vecNums.size(); i++)
	{
		cin>>vecNums[i];
	}
	Solution S1;
	cout << (S1.ContainsNearbyDupes(vecNums,k)?"True":"False") << endl;
}

