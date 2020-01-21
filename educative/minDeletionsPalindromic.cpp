#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int MinDeletionsPalindromic(const string & strInput)
{
	//same as determining the longest palindromic ss
	//total len - len of ss = min deletions
	
	//will store longest pss length for all substrings
	vector<vector<int>> vecSubs(strInput.length(),vector<int>(strInput.length(),0));

	//all 1 letter substrings are also p.s of len 1
	for(int i =0; i<vecSubs.size(); i++)
		vecSubs[i][i] =1;

	//build rest bottomup
	for(int j=1; j<vecSubs.size(); j++)
	{
		for(int i=0; i<vecSubs.size()-j; i++)
		{
			//looking at substring i to i+j

			//if ends match, then total pss length = 2 + length for remaining
			if (strInput[i] == strInput[i+j])
			{
				vecSubs[i][i+j] = 2+ (j>1?vecSubs[i+1][i+j-1]:0);
			}
			else
				vecSubs[i][i+j] = max(vecSubs[i+1][j],vecSubs[i][i+j-1]);
		}
	}

	return (strInput.length()-vecSubs[0][strInput.length()-1]);
	

}

int main()
{
	string str1 = "cde";
	printf("Min deletions to make %s palindromic are %d\n", str1.c_str(), MinDeletionsPalindromic(str1));
	return 0;

}
