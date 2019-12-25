#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> TripletSum(vector<int> vecInts)
{
	vector<vector<int>> vecResult;

	if(vecInts.size()<3) return vecResult;


	//first sort the array
	sort(vecInts.begin(),vecInts.end());


	//pick one number, for that try to find a matching pair with total sum zero
	
	for(int i=0; i<vecInts.size()-2; i++)
	{
		//ignore duplicates
		while(i>0 && vecInts[i]==vecInts[i-1]) i++;

		int left= i+1,right=vecInts.size()-1;
		while(left<right)
		{
			int sum = vecInts[i]+vecInts[left]+vecInts[right];
			if(sum==0)
			{
				vecResult.push_back(vector<int> {vecInts[i],vecInts[left],vecInts[right]});
				left++;
				right--;

				while(left<right)
				{
					if(vecInts[left]==vecInts[left-1])
						left++;
					else if (vecInts[right]==vecInts[right+1])
						right--;
					else
						break;
				}
			}
			else if (sum>0)
				right--;
			else
				left++;

		}

	}

	return vecResult;
}

int main()
{
	vector<int> vecInts = {-1,0,1,2,-1,-4};

	printf("The triplet with zero sum are : \n");

	vector<vector<int>> vecResult = TripletSum(vecInts);

	for(auto & entry : vecResult)
	{
		printf("triplet : ");
		for(auto & value: entry)
			printf(" %d",value);
		printf("\n");
	}
	return 0;
}
