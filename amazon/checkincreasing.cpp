#include <iostream>
#include <cstring>
#include <vector>


using namespace std;

class Solution
{
	public:
		bool IsBeautiful(vector<int> vecRow)
		{
			//iterate through the entire row
			//if it is in order increasing or decreasing 
			//or increasing then decreasing then we are good


			bool increasing = true;
			if (vecRow.size()<=2) return true;

			for(int i=1;i < vecRow.size(); i++)
			{
				bool test = increasing? vecRow[i] < vecRow[i-1] : vecRow[i] > vecRow[i-1];
				if (test && increasing)
					increasing = false;
				else if (test)
					return false;
			}

			return true;
		}

		int MinBeautiful(vector<int> vecRow)
		{
			//establish minimum number of deletions to make it obey the beautiful order

			//three things, partition, make beautiful left, make beautiful right
			

			// you need the minimum cuts that can make it beautiful
			

						

		}
};

int main()
{

	int size;
	cin >> size;
	vector<int> vecRow(size, 0);

	for(int i=0; i<vecRow.size(); i++)
	{
		cin >> vecRow[i];
	}

	Solution S1;
	cout << S1.IsBeautiful(vecRow);
	return 0;
}
