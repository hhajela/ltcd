#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<int> MaximalSubarrayWithIndices(vector<int> vecNums)
{
    int curSum = vecNums[0];
    int bestSum = vecNums[0];
    int start = 0, end =0;

    int bestStart= start;
    int bestEnd= end;

    for(int i=0; i<vecNums.size(); i++)
    {
        if(vecNums[i] > curSum+vecNums[i])
        {
            curSum = vecNums[i];
            start = end = i;
        }
        else
        {
            curSum += vecNums[i];
            end++;
        }
        
        if (curSum > bestSum)
        {
            bestSum = curSum;
            bestEnd = end;
            bestStart = start;
        }
    }

    return vector<int> {bestStart,bestEnd,bestSum};
}


int main()
{
    vector<int> vecInts = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> vecResult = MaximalSubarrayWithIndices(vecInts);
    printf("The maximal subarray is {%d,%d} with sum %d\n", vecResult[0], vecResult[1], vecResult[2]);
    //cout << "The maximal subarray is {" << vecResult[0] << "," << vecResult[1] << "} with sum " << vecResult[2] << endl;  UGLY
    return 0;
}