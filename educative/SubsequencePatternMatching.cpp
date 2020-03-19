#include <vector>
#include <iostream>

using namespace std;


int SPM(const string & strSearch, const string & strPat)
{
	//find occurrences
	if (strSearch.length() < strPat.length()) return 0;

	//create vector of subsolutions to store number of matches
	//for all possible combos of indices in search string and pattern
	vector<vector<int>> vecSubs(strSearch.length()+1,vector<int> (strPat.length()+1));

	//populate initial value for 0 characters included from pattern
	//1 match for all possible characters included from search string
	for(int i =0; i<vecSubs.size(); i++)
		vecSubs[i][0] = 1;

	//build rest of the values
	for(int i =1; i<vecSubs.size(); i++)
	{
		for(int j = 1; j<vecSubs[i].size(); j++)
		{
			//if the ith character from stringand jth from pattern match
			//number of matches = number of matches in i-1,j-1
			if (strSearch[i-1] == strPat[j-1])
				vecSubs[i][j] = vecSubs[i-1][j-1];
			
			//also add number of matches obtained from skipping this character from search string and matching remaining against pattern
			vecSubs[i][j] += vecSubs[i-1][j];
		}
	}

	return vecSubs.back().back();
}

int main(int argc, char ** argv)
{
	string str1;
	string str2; 
	if (argc>1)
	{
		str2 = argv[2];
		str1 = argv[1];
	}

	cout << "Number of occurrences of pattern in string " << SPM(str1,str2) << endl;
	return 0;
}
