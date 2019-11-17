#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string ToLower(char * a)
{
	string strLower(a,strlen(a));
	for(int i=0; i<strlen(a); i++)
	{
		strLower[i] = tolower(a[i]);
	}
	return strLower;
}

class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string>& banned) 
    {
	    //tokenize paragraph, check word is in banned set or not, if not
	    //then add to map of occurrences, keep track of most frequent word
	    //
	    //

	    unordered_set<string> setBanned(banned.begin(), banned.end());
	    unordered_map<string,int> mapFreq;
	    
	    char * copy = new char[paragraph.length()+1];
	    strncpy(copy,paragraph.c_str(),paragraph.length());
	    copy[paragraph.length()]='\0';

	    string mostCommonWord = "";
	    int nMaxFreq = 0;

	    char * curTok = strtok(copy, "!?',;. " );
	    while (curTok != NULL)
	    {
		    //if tolower of cur token is not in banned set increment frequency
		    string strLowWord = ToLower(curTok);

		    if(setBanned.find(strLowWord) == setBanned.end())
		    {
			    //not found in banned set , increment frequency

			    //try to find in map
			    mapFreq[strLowWord]++;

			    int freq = mapFreq[strLowWord];

			    if (freq>nMaxFreq)
			    {
				    mostCommonWord= strLowWord;
				    nMaxFreq = freq;
			    }
		    }

		    //find next

		    curTok = strtok(NULL, "!?',;. ");
			    
	    }

	    return mostCommonWord;
	 
        
    }
};

int main()
{
	Solution S1;
	return 0;
}
