#include <vector>
#include <cstdlib>
#include <iostream>
#include <chrono>


using namespace std;
using namespace std::chrono;

pair<int,int> LongestCommonSubstringRecursive(string str1, string str2, int i=0, int j=0);


string LongestCommonSubstring(string str1, string str2)
{
	pair<int,int> ret = LongestCommonSubstringRecursive(str1,str2);
	return str1.substr(ret.first,ret.second);
}


pair<int,int> LongestCommonSubstringRecursive(string str1, string str2, int i, int j)
{
	if (i>=str1.length() || j>=str2.length()) return pair<int,int> {0,0};

	int count = 0;
	int m = i;
	int n = j;
	while(m<str1.length() && n <str2.length() && str1[m++] == str2[n++])
		count++;

	pair<int,int> oneBranch = LongestCommonSubstringRecursive(str1,str2,i+1,j);
	pair<int,int> twoBranch = LongestCommonSubstringRecursive(str1,str2,i,j+1);

	//return pair with longest common ss
	return max(oneBranch.second,max(twoBranch.second,count))==count?pair<int,int> {i,count}:(max(oneBranch.second,twoBranch.second)==oneBranch.second?oneBranch:twoBranch);
}

string LongestCommonIterative(const string & str1, const string & str2)
{
	if (str1.empty() || str2.empty()) return "";

	//create vector to store common substring lengths till i and j
	vector<int> vecLengths(str2.length(),0);

	int maxLen =0;
	int maxIndex = 0;

	for(int i = 0; i<str1.length(); i++)
	{
		//iterate in reverse to avoid overwriting values
		for(int j = str2.length()-1; j>=0; j--)
		{
			//there is a common substring ending in i and j iff
			//ith and jth match, and then its length = 1 + length of lcs ending in i-1 and j-1

			//if ith and jth dont match, then no lcs or length =0
			
			vecLengths[j] = (str1[i]==str2[j])?1+(j>0?vecLengths[j-1]:0):0;

			if (vecLengths[j]>maxLen)
			{
				maxLen= vecLengths[j];
				maxIndex = j;
			}
		}
	}

	return str2.substr(maxIndex-maxLen+1,maxLen);
}

int main()
{
	string str1 = "abcdefg";
	string str2 = "jklmefgpqr";

	auto start = high_resolution_clock::now();
	string strLCS  = LongestCommonSubstring(str1,str2);
	auto stop = high_resolution_clock::now();
	printf("The longest common substring between %s and %s is %s, time taken to evaluate = %ld \n",str1.c_str(),str2.c_str(),strLCS.c_str(), duration_cast<microseconds>(stop-start).count());


	start = high_resolution_clock::now();
	strLCS  = LongestCommonIterative(str1,str2);
	stop = high_resolution_clock::now();
	printf("The longest common substring between %s and %s is %s, time taken %ld\n",str1.c_str(),str2.c_str(),strLCS.c_str(), duration_cast<microseconds>(stop-start).count());

	return 0;
}
