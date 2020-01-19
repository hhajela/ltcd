//abdbca

//1 letter substrings = a,b,d,b,c,a
//2 letter ss - ab bd db bc ca
//3 letter ss - abd bdb dbc bca
//
//
//n letter ss is a palindrome if first and last letters match and the remaining ss is a palindrome


#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int LPS(const string& strInput)
{
	//vector of subsolutions
	vector<vector<int>> vecSubs(strInput.length(),vector<int>(strInput.length(),-1));

	//initialize values for 1 letter substrings
	for(int i =0; i<vecSubs.size(); i++)
		vecSubs[i][i] =  1;

	int maxPalinLength =1;
	//build rest of values in bottom up
	for(int j=1; j<strInput.length(); j++)
	{
		for(int i =0; i<strInput.length()-j; i++)
		{
			//substring i, i+j is palindromic if i and i+j match
			//and the remaining substring is palindromic too

			if(strInput[i] == strInput[i+j] && (j>1?vecSubs[i+1][i+j-1]!=-1:true))
			{
				vecSubs[i][i+j] = 2 + vecSubs[i+1][i+j-1];
				if(vecSubs[i][i+j] > maxPalinLength) maxPalinLength = vecSubs[i][i+j];
			}
			else
				vecSubs[i][i+j] = -1;
		}
	}

	return maxPalinLength;

}


int main()
{
	string str1 = "abdbca";
	printf("The LPS length is %d\n", LPS(str1));
	return 0;
}

