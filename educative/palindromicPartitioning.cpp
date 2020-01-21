#include <vector>
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

vector<vector<int>> vecPals;
vector<int> vecMinCuts;

bool IsPalindrome(const string & strInput, int start, int end,bool bMemo = false)
{
	if (bMemo && vecPals[start][end] != -1)
		return static_cast<bool>(vecPals[start][end]);

	for(int i=0; i<(end-start+1)/2; i++)
		if (strInput[start+i] != strInput[end-i])
		{
			if (bMemo) vecPals[start][end] = 0;	
			return false;
		}

	if (bMemo) vecPals[start][end] = 1;
	return true;
}

int MinPalindromicCuts(const string & strInput, int start, int end, bool bMemo=false)
{
	//if string of length 1 or a palindrome no need to make a cut
	if (end<=start || IsPalindrome(strInput, start, end,bMemo)) return 0;

	//for all palindromic substrings starting at start, check if partitioning leads to minimum cuts
	
	if (bMemo && vecMinCuts[start] != -1) return vecMinCuts[start];

	int minCuts = end-start; //at most n-1 cuts
	for (int i = start; i<end; i++)
	{
		if (IsPalindrome(strInput,start,i,bMemo))
			minCuts= min(minCuts, 1 + MinPalindromicCuts(strInput, i+1, end, bMemo));
	}

	if (bMemo) vecMinCuts[start] = minCuts;
	return minCuts;
}

int MinPalindromicIterative(const string & strInput)
{
	//first check palindromes for all substrings
	auto vecPal = vector<vector<bool>>(strInput.length(),vector<bool>(strInput.length(),false));

	//all 1 letter ss are palindromes
	for(int i=0; i<vecPal.size(); i++)
		vecPal[i][i] = true;

	for(int j =1; j<vecPal.size(); j++)
	{
		for(int i=0; i<vecPal.size()-j; i++)
		{
			if (strInput[i] == strInput[i+j] && (j==1 || vecPal[i+1][i+j-1]))
			{
				vecPal[i][i+j] = true;
			}
		}
	}

	//vector to store minCuts for all starting positions till end
	vector<int> vecCuts(strInput.length(),0);

	for (int i= vecCuts.size()-1; i>=0; i--)
	{
		if (i==vecCuts.size()-1 || vecPal[i][vecCuts.size()-1])
		{
			vecCuts[i] = 0;
			continue;
		}

		int minCuts = vecCuts.size()-i-1;

		//figure out best partitioning
		for(int j = i; j<vecCuts.size()-1; j++)
		{
			if (vecPal[i][j])
				minCuts = min(minCuts, 1 + vecCuts[j+1]);
		}
		vecCuts[i] = minCuts;
	}

	return vecCuts[0];
}

int main()
{
	string str1 = "abbaefghtitikjhkgfhuyu";

	auto start = high_resolution_clock::now();
	int nRet = MinPalindromicCuts(str1,0,str1.length()-1);
	auto stop = high_resolution_clock::now();
	printf("recursive answer  %d, time taken %ld us\n", nRet, duration_cast<microseconds>(stop-start).count());


	start = high_resolution_clock::now();
	vecPals = vector<vector<int>>(str1.length(),vector<int>(str1.length(),-1));
	vecMinCuts = vector<int>(str1.length(),-1);
	nRet = MinPalindromicCuts(str1,0,str1.length()-1,true);
	stop = high_resolution_clock::now();
	printf("recursive answer  %d, time taken %ld us\n", nRet, duration_cast<microseconds>(stop-start).count());

	start = high_resolution_clock::now();
	nRet = MinPalindromicIterative(str1);
	stop = high_resolution_clock::now();
	printf("iterative answer %d, time taken %ld us\n", nRet, duration_cast<microseconds>(stop-start).count());
	return 0;
}
