#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<int> ProductOfArrayExceptSelf(vector<int> vecNums)
{
	// 1 2 3 4
	// 2*3*4 1*3*4 1*2*4 1*2*3
	//
	

	// 1   2  3 4
	// 1   1  2 6  product of all numbers prior to it
	// 24  12 4 1  product of all numbers after it
	// 24  12 8 6  multiply these 2
	

	//compute forwardProducts
	vector<int> vecResult(vecNums.size(),1);
	vector<int> backwardProducts(vecNums.size(), 1);
	for(int i=1; i<vecNums.size(); i++)
	{
		backwardProducts[i] = backwardProducts[i-1]*vecNums[i-1];
	}
	int curForwardProduct = 1;
	for(int j=vecNums.size()-2; j>=0; j--)
	{
		vecResult[j] = backwardProducts[j] * curForwardProduct*vecNums[j+1];
		curForwardProduct *= vecNums[j+1];
	}
	return vecResult;

}

string ToString(const vector<int> & somevec)
{
	stringstream ss;

	for(auto & num : somevec) ss << num << " ";

	return ss.str();
}


int main()
{
	vector<int> vecNums = {1,3,4,5};
	cout << "Product is " << ToString(ProductOfArrayExceptSelf(vecNums)) << endl;
	return 0;
}
