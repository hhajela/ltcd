#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

int CountUniqueWays(int m, int n)
{
	//can either come from above or from left
	//count both
	vector<int> vecWays(m);
	for(int i =0; i<m; i++)
		vecWays[i] = 1; //exactly one way to get to anywhere in the top row
	
	//calculate rest
	for(int i =1; i<n; i++)
	{
		//take sum of total ways from top and left
		//i.e. i-1,j and i,j-1
		for(int j =0; j<m; j++)
			vecWays[j] += (j>0?vecWays[j-1]:0);
	}

	return vecWays.back();
}

int main()
{
	int m;
	int n;
	cin >> m;
	cin >> n;
	printf("number of ways of getting to %d,%d from %d,%d are %d\n",0,0,m-1,n-1,CountUniqueWays(m,n));
    	return 0;	
}
