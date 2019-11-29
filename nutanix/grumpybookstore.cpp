#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution
{
    public:

    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) 
    {
        // iterate through the customer vector, keep track of the highest possible sum
        // and the sum for the current window

        int nCurSum = 0;
        int i=0;
        for(; i<X && i<customers.size(); i++)
            nCurSum += grumpy[i]*customers[i];
        
        int nBestSum = nCurSum;
        int j = i;
        int bestStart = 0;
        i=0;
        while (j < customers.size())
        {
            //shift window, adjust sum
            nCurSum += grumpy[j]*customers[j];


            nCurSum -= grumpy[i]*customers[i];
            i++;

            //cout << "cur sum" << nCurSum << endl;

            if (nBestSum < nCurSum)
            {
                nBestSum = nCurSum;
                bestStart = i;
            }
            
            j++;

        }

        //cout << "best start " << bestStart << endl;
        int totalSatisfied = 0;
        //compute total satisfied customers
        for(int i=0; i<customers.size(); i++)
        {
            if(grumpy[i]==0 || (i>=bestStart && i<(bestStart+X)))
                totalSatisfied += customers[i];
        }

        return totalSatisfied;

    }
};



int main()
{
    /*
    vector<int> customers = {1,0,1,2,1,1,7,5};
    vector<int> grumpy = {0,1,0,1,0,1,0,1}; 
    int X = 3;
    */

    vector<int> customers = {4,10,10};
    vector<int> grumpy = {1,1,0}; 
    int X = 2;
    Solution S1;
    cout << " max customers = " << S1.maxSatisfied(customers, grumpy, X);

    return 0;
}
