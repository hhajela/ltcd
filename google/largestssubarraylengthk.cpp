#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
    public:
    
    vector<int> LargestSubarrayLengthK(vector<int> vec1, int k)
    {
	    //iterate through all possible subarrays
	    int bestStart = 0;
	    for(int i=1; i<=vec1.size()-k; i++)
	    {
		    int offset = 0;
		    while(offset < k)
		    {
			    //cout << "comparing " << i << " and " << bestStart << endl; 
			    if (vec1[i+offset] == vec1[bestStart+offset])
			    {
				    offset++;
				    continue;
			    }

			    if (vec1[i+offset] > vec1[bestStart+offset])
				    bestStart=i;

			    break;
		    }
	    }
	    return vector<int>(vec1.begin()+bestStart, vec1.begin()+bestStart+k);
    }    
};

int main() 
{
    vector<int> vec1 = {9, 9, 6, 9, 9, 9};
    Solution S1;
    for (auto x : S1.LargestSubarrayLengthK(vec1,3))
    {
        cout << x << endl;
    }
	return 0;
}
