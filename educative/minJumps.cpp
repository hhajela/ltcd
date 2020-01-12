#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits>

using namespace std;


int MinJumpsToEnd(vector<int> vecJumps)
{
	//min ways of getting to last = 1 + min jumps to get to any steps in range of it
	
	//subsolution vector stores min way of getting to an index from 0
	vector<int> vecSubs(vecJumps.size(),numeric_limits<int>::max());

	vecSubs.front()=0; 
	for(int i=0; i<vecJumps.size(); i++)
	{
		//update all indices in range of ith
		for(int j = i+1; j<=i+vecJumps[i] && j<vecJumps.size();j++)
			vecSubs[j] = min(vecSubs[i]+1,vecSubs[j]);
	}
	return vecSubs.back();

}


int main()
{
	vector<int> vecJumps {1,1,3,6,9,3,0,1,3};
	printf("Min jumps to end is %d\n",MinJumpsToEnd(vecJumps));
	return 0;
}
