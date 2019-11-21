#include <vector>
#include <iostream>


using namespace std;


class Solution
{
	public:

	vector<int> GetLargestSubarrayK(vector<int> nums, int k)
	{

		//iterate through the aray from 0 to n-k th index
		//
		//

		int greatest = nums[0];
		int start = 0;

		for(int i =0; i<=nums.size()-k; i++)
		{
			if (nums[i]>greatest)
			{
				greatest = nums[i];
				start = i;
			}
		}

		vector<int> vResult(nums.begin()+start, nums.begin()+start+k);
		return vResult;
	}
};

int main()
{
	vector<int> vec1 = {1, 4, 3, 2, 5};
	Solution S1;
	for (auto x : S1.GetLargestSubarrayK(vec1,4))
	{
		cout << x << endl;
	
	}
	return 0;

}
