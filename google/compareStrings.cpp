#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int GetStringSize(const string & str1)
{
  //cout << "evaluating size of " << str1 << " ";
  if (str1.empty())
    return 0;

  vector<char> vecFreq(26,0);
  //get the smallest, calculate frequencies for all
  char smallest = str1[0];
  for (auto & curChar : str1)
  {
    if (curChar < smallest)
      smallest = curChar;
    
    vecFreq[curChar-'a']++;
  }

  //return freq of smallest
  //cout << " = " << static_cast<int>(vecFreq[smallest]);
  return static_cast<int>(vecFreq[smallest-'a']);
}

int GetNumBiggerStrings(const vector<int> & vec1, int size)
{
  int first=0;
  int last= vec1.size()-1;
  int mid;

  while(last>=first)
  {
     mid = (first+last)/2;
    if (vec1[mid]>size)
      last = mid-1;
    else if (vec1[mid] < size)
      first = mid+1;
    else
    {
      while (mid >= 0 && vec1[mid] == size)
        mid--;

      return mid+1;
    }
    
  }

  if (first>vec1.size()-1)
    return vec1.size();
  else if (last<0)
    return 0;
  else
    return last+1;
}

class Solution
{
  public:

  vector<int> GetGreaterStrings(const string & str1, const string&  str2)
  {

    vector<string> vec1;
    istringstream stream1(str1);
    string strTemp;
    while(getline(stream1,strTemp,','))
      vec1.push_back(strTemp);

    vector<string> vec2;
    stream1 = istringstream(str2);
    while(getline(stream1,strTemp,','))
      vec2.push_back(strTemp);

    //calculate frequencies for all the strings in vec1
    vector<int> freq1;
    for(auto & curString: vec1)
    {
	    //cout << "hmm";
      freq1.push_back(GetStringSize(curString));
    }

    //sort freq1
    sort(freq1.begin(), freq1.end());

    //for each string in vec, calculate size, do a binary search in freq1
    vector<int> vecResult;
    for(auto & curString: vec2)
    {
      int curSize = GetStringSize(curString);

      vecResult.push_back(GetNumBiggerStrings(freq1, curSize));
    }

    return vecResult;
  }

};

int main() 
{
  Solution S1;
  string str1 = "abcd,aabc,bd";
  string str2 = "aaa,aa";
  for (auto & x : S1.GetGreaterStrings(str1, str2))
  {
    cout << x << " ";
  }
  return 0;
}
