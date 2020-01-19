#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;


int LPS(const string & strInput)
{
	//build lps length from 1 letter palindromes
	
	vector<vector<int>> vecSubs(strInput.length(),vector<int>(strInput.length(),-1));

	//initialize LPS length for 1 letter palindromes
	for (int i =0; i<vecSubs.size(); i++)
	{
		vecSubs[i][i]= 1; 
	}

	//build bigger palindromes in bottom up fashion
	for(int j=1; j<strInput.length(); j++)
	{
		//for every possible starting position
		for(int i = 0; i<strInput.length()-j; i++)
		{
			//if the current ends match
			if(strInput[i] == strInput[i+j])
			{
				// length becomes 2 + length for remaining chars in th emiddle
				vecSubs[i][i+j] = 2 + (j>1?vecSubs[i+1][i+j-1]:0);
			}
			else
			{
				//ends dont match pick the best of n-1 length left and right substrings
				vecSubs[i][i+j] = max(vecSubs[i+1][i+j], vecSubs[i][i+j-1]);
			}
		}
	}

	return vecSubs[0][strInput.length()-1]; //corresponds to the total string length
}


int main()
{
	string str1 = "adbecfbga";
	printf("LPS length is %d \n", LPS(str1));
	return 0;
}

