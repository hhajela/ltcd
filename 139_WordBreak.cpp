#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

bool CanSegment(const string & strCandidate, const vector<string> & vecWords)
{
	if (vecWords.empty() && !strCandidate.empty())
		return false;

	//initialize vector of subsolutions 
	//whether it is possible to segment at a particular point
	vector<bool> vecSubs(strCandidate.length()+1,false);
	vecSubs[0] = true; //should always be able to segment empty string

	//loop through all characters and figure out if can segment
	for(int c = 0; c<strCandidate.length(); c++)
	{
		vecSubs[c+1] = false;
		//loop through all possible words
		for(int j = 0; j<vecWords.size(); j++)
		{
			//check if you can segment using this word
			int startPos = c+1-static_cast<int>(vecWords[j].length());
			if (startPos>=0 && strCandidate.compare(startPos,vecWords[j].length(),vecWords[j]) == 0)
				vecSubs[c+1] = vecSubs[startPos] || vecSubs[c+1];
		}
	}

	return vecSubs.back();

}

int main()
{
	string strCandidate;
	getline(cin,strCandidate);

	string strLine;
	getline(cin,strLine);
	stringstream ss(strLine);

	int nLength;
	ss >> nLength;

	vector<string> vecWords(nLength);
	for(int i =0; i<nLength; i++)
	{
		getline(cin, vecWords[i]);
	}

	cout << "Segmentation can be done : " << (CanSegment(strCandidate,vecWords)?"Yes":"No") << endl;

	return 0;
}
