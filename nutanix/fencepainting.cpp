#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>


using namespace std;

class Solution
{
	public:

	int NumberOfWaysToPaint(vector<int> vecFence)
	{
		if (vecFence.empty()) return 0;

		int nWays  = 0;
		int nZeros = 0;
		int nOnes = 1;
		bool lastWasOne = false;

		int i = 0;
		while(i<vecFence.size()  && vecFence[i] != 1) i++;

		if (i<vecFence.size()) nWays =1;

		for(; i<vecFence.size(); i++)
		{
			if (vecFence[i]==1)
			{
				if(lastWasOne)
				{
					nOnes++;
				}
				else
				{
					nWays *= nZeros+1;
					nZeros = 1;
					lastWasOne = true;
				}
			}
			else
			{
				if(lastWasOne)
				{
					lastWasOne = false;
					nWays *= pow(2,nOnes-1);
					nOnes = 1;
				}
				else
				{
					nZeros++;
				}
			}
		}

		return nWays;
	}
};

int main(int argc, char ** argv)
{
	string input = argc > 1 ? argv[1] : "001101";
	vector<int> vecFence;

	for (int i=0; i< input.length(); i++)
	       vecFence.push_back(atoi(input.substr(i,1).c_str()));
	Solution S1;
	cout << S1.NumberOfWaysToPaint(vecFence);
	return 0;	
}
