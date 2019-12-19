#include <iostream>
#include <vector>


using namespace std;


int FindKthMissingElement(vector<int> vecNums, int k)
{
	//first get the position that corresponds to the 0th element
	
	// 1 5 6 7 8 11 12 13
	
	int offset= vecNums[0];

	//do a binary search for a number that satisfies the missing number criteria
	
	int left = 0;
	int right = vecNums.size()-1;
	int mid;

	while(left <right)
	{
		mid = (left+right)/2;

		//cout << "left " << left << "right " << right << "mid " << mid << endl;

		int missingValues = vecNums[mid]-offset-mid;

		if (missingValues < k)
		{
			left = mid+1;
		}
		else // missingValues >= k
		{
			right = mid; //so that we alwasy at least include one value for ==k
		}
	}
//	cout << mid << endl;
	return vecNums[right-1] + k - (vecNums[right-1]-offset-right+1);
}


int main()
{
	int sz;
	cin >> sz;
	int k;
	cin >> k;

	vector<int> vecNums;

	for(int i=0; i<sz;i++)
	{
		int temp;
		cin >> temp;
		vecNums.push_back(temp);
	}

	cout << "Kth missing element is " << FindKthMissingElement(vecNums,k) << endl;

	return 0;
}
