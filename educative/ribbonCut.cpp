#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int MaximumRibbonCut(vector<int> vecLengths, int nLength)
{
	//subsolutions will store maximum number of cuts for a given index and all total ribbon length
	vector<int> vecSubs(nLength+1,-1);

	//init for first length
	for(int i=0; i<=nLength; i++)
		vecSubs[i] = (i%vecLengths.front()==0)? i/vecLengths.front() : -1; //if length div by first item no of cuts = total /length

	//build rest of the values
	for(int i =1; i<vecLengths.size(); i++)
	{
		for(int t =0; t<vecSubs.size();t++)
		{
			//possibility one is that this length was included
			//number of cuts = 1 for this plus maximum possible for total-current
			int nIncluded = t<vecLengths[i]? 0 : (vecSubs[t-vecLengths[i]] == -1)?-1:vecSubs[t-vecLengths[i]]+1;

			//if excluded then maximum cuts = current value of vecsubs[t]
			vecSubs[t] = max(vecSubs[t], nIncluded);
		}

	}

	for(auto & num: vecSubs)
		cout << num << " ";
	cout << endl;

	return vecSubs.back();
}


int main()
{
	vector<int> vecLengths = {2,3,5};

	int nRibbonLength = 5;
	printf("maximum ribbon cuts for length %d is %d\n",nRibbonLength, MaximumRibbonCut(vecLengths,nRibbonLength));
	return 0;
}
