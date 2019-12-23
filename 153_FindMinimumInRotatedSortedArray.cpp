#include <iostream>
#include <vector>
#include <cstdlib>


using namespace std;

int FindMinimumInRotatedSortedArray(vector<int> vecNums)
{
	//find pivot point
	
	//array not rotated means last > first
	if(vecNums.size()==1 || vecNums.back() > vecNums.front()) return vecNums.front();

	//else see if you are in rotated part (elements greater than 0th)
	//or non rotated part (elements less than 0th)
	
	int left=0,right = vecNums.size()-1,mid;
	while(left<=right)
	{
		mid = (left+right)/2;

		if(vecNums[mid] > vecNums[mid+1])
			return vecNums[mid+1];
		else if (vecNums[mid-1] > vecNums[mid])
			return vecNums[mid];
		else if (vecNums[mid] > vecNums[0]) // rotated part, move right
			left = mid+1;
		else
			right = mid-1; //non rotated, move left
	}

	return vecNums[mid];
}

int main()
{
	vector<int> vecInts = {2,1};
	printf("The minimum element in rotated array is %d\n", FindMinimumInRotatedSortedArray(vecInts));
	vecInts = {4,5,6,1,2,3};
	printf("The minimum element in rotated array is %d\n", FindMinimumInRotatedSortedArray(vecInts));
	vecInts = {1,2,3};

	printf("The minimum element in rotated array is %d\n", FindMinimumInRotatedSortedArray(vecInts));
	
	return 0;
}
