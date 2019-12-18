#include <iostream>
#include <cstring>
#include <chrono>
#include <unordered_map>


using namespace std;

class Solution
{
	public:
	
	unordered_map<int,unsigned long> mapLookup;
	
	int NumUniqueBST(int num)
	{
		//base cases

		if(num==2)
			return 2;
		else if (num <=1)
			return 1;
		else if (mapLookup.find(num) != mapLookup.end())
			return mapLookup[num];

		int nTotalWays = 0;
		for(int i=0; i<num; i++)
		{
			nTotalWays += NumUniqueBST(i)*NumUniqueBST(num-i-1);
		}

		mapLookup[num] = nTotalWays;
		return nTotalWays;
	}

};



int main(int argc, char ** argv)
{
	int num = atoi(argv[1]);

	Solution S1;

	auto start = chrono::high_resolution_clock::now();
	int numways = S1.NumUniqueBST(num);
	auto stop = chrono::high_resolution_clock::now();

	auto duration = chrono::duration_cast<chrono::microseconds>(stop-start);
	cout << "Number of ways " << numways << ", Execution time was " << duration.count() << " microseconds" << endl;

	return 0;
}
