#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> CountBits(int num)
{
	vector<int> vecResult(num+1,0);

	vecResult[0] = 0;

	for(int i=1; i<=num; i++)
	{
		vecResult[i] = vecResult[i/2] + i%2;
	}
	return vecResult;
}


int main(int argc, char ** argv)
{
	int num = argc>1?(atoi(argv[1])):5;
	vector<int> vecNums = CountBits(num);

	cout << endl;
	for(auto & num: vecNums) cout << num << endl;
}
