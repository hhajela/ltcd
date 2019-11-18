#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
    public:
    
    vector<int> LargestSubarrayLengthK(vector<int> vec1, int k)
    {
        // array of length n will have n-k subarrays of length k
        // figure out all subarrays of lenght k
        
        //start comparing all elements of each subarrays
        int offset = 0;
        int startGreatest = 0;
        int endGreatest = k-1;
        bool tie = true;
        vector<bool> eliminatedStarts(vec1.size(), false);
        
        while(tie && offset < k)
        {
            tie = false;
            int curGreatestElement = INT_MIN;
            for (int j=offset;j<=vec1.size()-k+offset;j++)
            {
                //cout << "currently considering " << vec1[j] << " ";
                if (eliminatedStarts[j-offset])
                    continue;
                
                if (vec1[j]>curGreatestElement)
                {
                  //cout << "new greatest for offset " << offset << " ";
                  startGreatest= j-offset;
                  endGreatest = startGreatest+k-1;
                  curGreatestElement = vec1[j];
                }
                else if (vec1[j] == curGreatestElement)
                {
                  //cout << "its a tie ";
                  tie = true;
                }
                else
                {
                  eliminatedStarts[j-offset]= true;
                  //cout << j-offset << " eliminated" << endl;
                }
                //cout << endl;
            }
            
            offset++;
        }
        
        vector<int> vecResult;
        //cout << startGreatest << " " << endGreatest << endl;
        for(int i =startGreatest; i<=endGreatest; i++)
            vecResult.push_back( vec1[i]);
            
        return vecResult;
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
