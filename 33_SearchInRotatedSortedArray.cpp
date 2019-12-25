#include <iostream>
#include <vector>

using namespace std;

int SearchInRotatedSortedArray(vector<int> vecNums, int target)
{
	//first find the pivot of rotation
	int pivot = 0;
	if(vecNums.size()>1 && vecNums.back() <= vecNums.front())
	{
		int left=0,right=vecNums.size()-1,mid;

		while(left<=right)
		{
			mid = (left+right)/2;
			
			if (vecNums[mid]>vecNums[mid+1])
			{
				pivot = mid+1;
				break;
			}
			else if (vecNums[mid-1]>vecNums[mid])
			{
				pivot = mid;
				break;
			}
			else if (vecNums[mid] >= vecNums[0])
				left = mid+1;
			else
				right = mid-1;
		}
	}

	//do binary search in rotated array, map orig to target indices
	
	int left=0,right=vecNums.size()-1,mid,mappedMid;

	while(left<=right)
	{
		mid = (left+right)/2;

		//map mid to rotated indices
		mappedMid = (pivot+mid)%vecNums.size();

		if (vecNums[mappedMid]==target)
			return mappedMid;
		else if (vecNums[mappedMid]>target)
			right = mid-1;
		else
			left = mid+1;
	}

	return -1;
}



int main()
{
	vector<int> vecRotated= {4,5,6,7,8,0,1,2,};

	printf("Index of 6 in rotated array %d\n", SearchInRotatedSortedArray(vecRotated,6));
	printf("Index of 1 in rotated array %d\n", SearchInRotatedSortedArray(vecRotated,1));
	printf("Index of 11 in rotated array %d\n", SearchInRotatedSortedArray(vecRotated,11));

	return 0;
}
