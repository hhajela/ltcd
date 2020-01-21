#include <vector>
#include <iostream>

using namespace std;

bool IsPalindrome(const string & strInput, int start, int end)
{
	for(int i=0; i<(end-start+1)/2; i++)
		if (strInput[start+i] != strInput[end-i]) return false;

	return true;
}

int MinPalindromicCuts(const string & strInput, int start, int end)
{
	//if string of length 1 or a palindrome no need to make a cut
	if (end<=start || IsPalindrome(strInput, start, end)) return 0;

	//for all palindromic substrings starting at start, check if partitioning leads to minimum cuts
	
	int minCuts = end-start; //at most n-1 cuts
	for (int i = start; i<end; i++)
	{
		if (IsPalindrome(strInput,start,i))
			minCuts= min(minCuts, 1 + MinPalindromicCuts(strInput, i+1, end));
	}
	return minCuts;
}

int main()
{
	string str1 = "abad";
	printf("Min cuts to divide %s into palidnromic partitions are %d\n", str1.c_str(), MinPalindromicCuts(str1,0, str1.length()-1));
	return 0;
}
