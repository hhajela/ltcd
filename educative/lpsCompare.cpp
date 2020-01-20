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
#include <chrono>

using namespace std;

vector<vector<int>> vecSubs;

string LPS(const string& strInput)
{
	//vector of subsolutions
	vector<vector<bool>> vecSubs(strInput.length(),vector<bool>(strInput.length(),false));

	//initialize values for 1 letter substrings
	for(int i =0; i<vecSubs.size(); i++)
		vecSubs[i][i] = true;

	int maxStart  = 0;
	int maxPalinLength =1;
	//build rest of values in bottom up
	for(int j=1; j<strInput.length(); j++)
	{
		for(int i =0; i<strInput.length()-j; i++)
		{
			//substring i, i+j is palindromic if i and i+j match
			//and the remaining substring is palindromic too

			if(strInput[i] == strInput[i+j] && (j>1?vecSubs[i+1][i+j-1]:true))
			{
				vecSubs[i][i+j] = true;
				if(j+1 > maxPalinLength)
				{
					maxStart = i;
					maxPalinLength = j+1;
				}
			}
			else
				vecSubs[i][i+j] = false;
		}
	}

	return strInput.substr(maxStart, maxPalinLength);

}

int MaxLPS(const string & strInput, int start, int end, bool bMemo, int& nMaxStart, int& nMaxLen);

string LPSRecursive(const string & strInput, bool bMemo)
{
	//substring of length n is a palindrome if ends match and remaining are palindrome
	if (strInput.empty()) return strInput;

	int nMaxStart = 0;
	int nMaxLen = 1;
	MaxLPS(strInput, 0, strInput.length()-1, bMemo, nMaxStart, nMaxLen);

	return strInput.substr(nMaxStart,nMaxLen);
}

int MaxLPS(const string & strInput, int start, int end, bool bMemo, int& nMaxStart, int& nMaxLen)
{
	if (start>end)
		return 0;
	if (start == end)
		return 1;

	if(bMemo && vecSubs[start][end] != -1)
		return vecSubs[start][end];
	
	//if ends match and remaining is palindromic then whole thing is a palindrome
	if (strInput[start] == strInput[end] && MaxLPS(strInput,start+1,end-1,bMemo,nMaxStart,nMaxLen)==(end-start-1))
	{
		if (nMaxLen < (end-start+1))
		{
			nMaxLen = end-start+1;
			nMaxStart =start;
		}
		if (bMemo) vecSubs[start][end] = end-start+1;
		return end-start+1;
	}
	else // look into the substrings
	{
		int nRet = max(MaxLPS(strInput,start+1,end,bMemo,nMaxStart,nMaxLen),MaxLPS(strInput,start,end-1,bMemo,nMaxStart,nMaxLen));
		if (bMemo) vecSubs[start][end] = nRet;
		return nRet;
	}
}


string AddSeps(const string & strInput)
{
	//abcd -> |a|b|c|d|
	string strRet(strInput.length()*2+1,'|');

	for(int i =0; i<strInput.length(); i++)
	{
		strRet[2*i+1]= strInput[i];
	}
	return strRet;
}

string LPSManacher(const string & strInput)
{
	//use reference palindromes to figure out length of other palindromes
	//add boundaries

	string strTemp = AddSeps(strInput);

	vector<int> vecLen(strTemp.length(),0);

	int c = 0;
	int r = 0;
	int m,n;
	m=n=0;

	int nMaxStart = 0;
	int nMaxLen = 0;
	//figure out lengths for all possible centers
	for(int i =1; i<vecLen.size(); i++)
	{
		if (i>r)
		{
			vecLen[i] = 0;
			m= i-1;
			n=i+1;
		}
		else
		{
			int i_ = 2*c - i;
			if(vecLen[i_] < r-i-1)
			{
				vecLen[i] = vecLen[i_];
				m = -1;
			}
			else
			{
				vecLen[i] = r-i;
				n = r+1;
				m = 2*i - n;
			}
		}

		//xtend len till mismatch
		while(m>=0 && n<strTemp.length() && strTemp[m] == strTemp[n])
		{
			vecLen[i]++;
			m--;
			n++;
		}

		//update center and best match till this point
		if ((i+vecLen[i])> r)
		{
			r = i + vecLen[i];
			c = i;
		}

		if(nMaxLen < (2*vecLen[i]+1))
		{
			nMaxStart = i-vecLen[i];
			nMaxLen = 2* vecLen[i]+1;
		}
	}

	//extract lps and remove seps
	string strLPS = strTemp.substr(nMaxStart,nMaxLen);

	string strRet;
	for(int i =1; i<strLPS.length(); i+=2)
		strRet += strLPS[i];
	
	return strRet;
}

int main()
{
	string str1 = "abedgfhabcdcbatyuabddbal";

	auto start = chrono::high_resolution_clock::now();
	string strLPS = LPSRecursive(str1,false);
	auto stop = chrono::high_resolution_clock::now();

	printf("LPS Recursive answer %s, time taken %ld us\n", strLPS.c_str(), chrono::duration_cast<chrono::microseconds>(stop-start).count());

	strLPS.clear();
	start = chrono::high_resolution_clock::now();
	vecSubs = vector<vector<int>>(str1.length(),vector<int>(str1.length(),-1));
	strLPS = LPSRecursive(str1, true);
	stop = chrono::high_resolution_clock::now();

	printf("LPS recursive with memoization answer %s, time taken %ld us\n", strLPS.c_str(), chrono::duration_cast<chrono::microseconds>(stop-start).count());

	strLPS.clear();
	start = chrono::high_resolution_clock::now();
	strLPS = LPS(str1);
	stop = chrono::high_resolution_clock::now();

	printf("LPS iterative answer %s, time taken %ld us\n", strLPS.c_str(), chrono::duration_cast<chrono::microseconds>(stop-start).count());

	strLPS.clear();
	start = chrono::high_resolution_clock::now();
	strLPS = LPSManacher(str1);
	stop = chrono::high_resolution_clock::now();

	printf("LPS manacher answer %s, time taken %ld us\n", strLPS.c_str(), chrono::duration_cast<chrono::microseconds>(stop-start).count());

	return 0;
}

