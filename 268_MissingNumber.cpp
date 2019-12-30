#include <iostream>
#include <vector>

using namespace std;

int GetMissingNumber(vector<int> vecNums)
{
	int i = 1;
	int result = 0;

	for(auto & num : vecNums)
	{
		result ^= num;
		result ^= i;
		i++;
	}

	return result;

}

int main()
{
	vector<int> vecNums = {0,3,5,6,1,4,7};
	cout << "missing number is " << GetMissingNumber(vecNums) << endl;
	vecNums = {4,1,3,2,0};
	cout << "missing number is " << GetMissingNumber(vecNums) << endl;
	return 0;
}
