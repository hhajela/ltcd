#include <iostream>
#include <vector>
#include <sstream>


using namespace std;


class Solution
{
	public:

	int GetStringSize(const string & str1)
	{
		vector<char> frequencies(26,0);
		char smallest = str1[0];

		for (auto & curChr : str1)
		{
			if (curChr < smallest)
				smallest = curChr;

			frequencies[curChr-'a']++;
		}
		return static_cast<int>(frequencies[smallest-'a']);
	}
	
	vector<int> CompareStrings(const string& str1,const string& str2)
	{
		vector<string> vec1, vec2;
		string strTemp;
		istringstream iStream(str1);
		while(getline(iStream,strTemp,','))
			vec1.emplace_back(strTemp);
		
		iStream = istringstream(str2);
		while(getline(iStream,strTemp,','))
			vec2.emplace_back(strTemp);

		// compute the sizes of all strings in vec
		// keep frequency occurrences b/w 0 and 10 in array
		// calculate how many times each freq occurs finally make it cumulative
		
		vector<int> vecCumulative(11,0);

		for(auto & curString: vec1)
			vecCumulative[GetStringSize(curString)]++;

		for(int i=1; i<vecCumulative.size(); i++)
			vecCumulative[i] += vecCumulative[i-1];

		vector<int> vecRes;
		//calculate size of each string in vec2, compare to vecCumulative
		for (auto & curString: vec2)
		{
			int size = GetStringSize(curString);

			vecRes.emplace_back(size>0 ? vecCumulative[size-1] : 0);
		}
		return vecRes;

	}
};


int main()
{
	string str1 = "abcd,aabc,bd";
	string str2 = "aaa,aa";	

	Solution S1;
	for (auto & x: S1.CompareStrings(str1,str2))
		cout << x << " ";

	return 0;
}
