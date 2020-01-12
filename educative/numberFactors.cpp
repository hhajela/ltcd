#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>

using namespace std;

int NumberFactors(int nTarget)
{
	//calculate basic cases
	vector<int> vecTemp = {1,1,2,4}; //number of ways of representing upto 4

	if (nTarget<5) return vecTemp[nTarget-1];

	int cur;
	//calculate rest
	for(int i = 4; i<nTarget; i++)
	{
		//ith value = number of ways of representing i-1 + i-3 + i-4
		//so keep track of previous 4 values
		cur = vecTemp[0]+vecTemp[1]+vecTemp[3];
		for(int i =0; i<vecTemp.size()-1; i++)
			vecTemp[i] = vecTemp[i+1];
		vecTemp.back()=cur;
	}
	return cur;

}




int main(int argc, char ** argv)
{
	int nTarget = (argc>1)?atoi(argv[1]):6;
	printf("Number of ways of expressing %d as a sum of 1,3 and 4 is %d\n",nTarget,NumberFactors(nTarget));
	return 0;
}
