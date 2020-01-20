#include <vector>
#include <chrono>
#include <cstdlib>
#include <iostream>


using namespace std;
using namespace std::chrono;


int CountPalindromicSS(const string & strInput)
{
	auto vecSubs = vector<vector<bool>>(strInput.length(),vector<bool>(strInput.length(),false));

	int nPalindromeCount = 0;

	//all 1 letter sstrings are palidnromes
	for(int i=0; i<vecSubs.size(); i++)
	{
		vecSubs[i][i] = true;
		nPalindromeCount++;
	}
	
	//calculate values bottom up
	for(int j =1; j<vecSubs.size(); j++)
	{
		for(int i= 0; i<vecSubs.size()-j; i++)
		{
			//cout << strInput.substr(i,j+1) << endl;
			//is a palindromic ss if ends match and remaining characters are palindromic
			if (strInput[i] == strInput[i+j] && (j>1?(vecSubs[i+1][i+j-1]):true))
			{
				nPalindromeCount++;
				vecSubs[i][i+j] = true;
			}
			else
				vecSubs[i][i+j] = false;

		}
	}

	return nPalindromeCount;
}

string AddSeparators(const string & strInput)
{
	string strRet(strInput.length()*2+1,'|');
	for(int i=0; i<strInput.length(); i++)
		strRet[2*i+1] = strInput[i];

	return strRet;
}

int CountPSSLinear(const string & strInput)
{
	//add sep
	string strTemp = AddSeparators(strInput);

	//vector to keep track of lengths
	vector<int> vecLen(strTemp.length(),0);

	int c =0;
	int r =0;
	int m,n;
	m=n=0;

	for(int i =1; i<vecLen.size(); i++)
	{
		if (i>r)
		{
			vecLen[i] = 0;
			m = i-1;
			n = i+1;
		}
		else
		{
			int i_ = 2*c -i;
			if(vecLen[i_] < r-i-1)
			{
				vecLen[i] = vecLen[i_];
				m=-1;
			}
			else
			{
				vecLen[i] = r-i;
				n = r+1;
				m = 2*i - n;
			}
		}

		//calculate how far they go
		while(m>=0 && n<strTemp.length() && strTemp[m] == strTemp[n])
		{
			vecLen[i]++;
			m--;
			n++;
		}

		if ((vecLen[i]+i)>r)
		{
			r = i + vecLen[i];
			c = i;
		}
	}

	int nPSCount = 0;

	//now every element of vecLen tells the half length of the palindrome at that index
	for(int i=0; i<vecLen.size()-1; i++)
	{
		//cout << vecLen[i] << endl;
		nPSCount += vecLen[i];
	}

	return nPSCount;
}


int main()
{
	string str1 = "abcdfgfhijkjk";

	auto start = high_resolution_clock::now();
	int nCount = CountPalindromicSS(str1);
	auto stop = high_resolution_clock::now();

	printf("Time elapsed for iterative method %ld us\n",duration_cast<microseconds>(stop-start).count());


	start = high_resolution_clock::now();
	nCount = CountPSSLinear(str1);
	stop = high_resolution_clock::now();

	printf("Time elapsed for linear method %ld us\n",duration_cast<microseconds>(stop-start).count());
	return 0;
}

