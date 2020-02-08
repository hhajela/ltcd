#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

int LongestCommonSS(const string & str1, const string & str2, int i=0, int j=0, int count=0)
{
  if (i>=str1.length() || j>=str2.length()) return 0;

  //if ith and jth same add one to count
  int count1 = 0;
  if (str1[i]==str2[j])
    count1 = 1 + LongestCommonSS(str1,str2,i+1,j+1, count);

  int count2 = LongestCommonSS(str1,str2,i+1,j,count);

  int count3 = LongestCommonSS(str1,str2,i,j+1,count);

  return max(count1,max(count2,count3));
}

int LongestCommonSSIterative(const string & str1, const string & str2)
{
  //consider substrings ending in i and j indices
  //length of common subsequence ending in i and j = length of common ss ending in i-1 and j-1 +1 if i and j are equal
  //otherwise length of common ss = max of i-1,j or i,j-1

  //  p a s s p o r t
  //p 1 1 1 1 1 1 1 1 
  //s 1 1 2 2 2 2 2 2
  //s 1 1 2 3 3 3 3 3
  //p 1 1 2 3 4 4 4 4
  //t 1 1 2 3 4 4 4 5

  auto vecSubs = vector<vector<int> >(2,vector<int>(str1.length(),0));

  for (int j =0; j<str2.length(); j++)
  {
    for(int i =0; i<str1.length(); i++)
    {
      //lc ss ending in i and j = 1 + lcs ending in i-1 and j-1
      int oneWay = str1[i]==str2[j]?(1+ (i>0 && j>0?vecSubs[(j-1)%2][i-1]:0)):0;
      
      int twoWay = j>0?vecSubs[(j-1)%2][i]:0;
      int threeWay = i>0?vecSubs[j%2][i-1]:0;

      vecSubs[j%2][i] = max(oneWay,max(twoWay,threeWay));
    }
  }
  /*
  for (int i=0; i<vecSubs.size();i++)
  {
    for(int j =0; j<vecSubs[i].size(); j++)
      cout << vecSubs[i][j] << " ";
    cout << endl;
  }*/

  return vecSubs.back().back();
}

int main() {

  string str1 = "passport";
  string str2 = "ppsspt";

  auto start = high_resolution_clock::now();
  int retValue = LongestCommonSSIterative(str1,str2);
  auto stop = high_resolution_clock::now();
  printf("Iterative method, Longest common ss length is %d and evaluation time is %ld us\n",retValue , duration_cast<microseconds>(stop-start).count() );

  start = high_resolution_clock::now();
  retValue = LongestCommonSS(str1,str2);
  stop = high_resolution_clock::now();
  printf("Recursive method, Longest common ss length is %d and evaluation time is %ld us\n", retValue, duration_cast<microseconds>(stop-start).count() );

  return 0;
}
