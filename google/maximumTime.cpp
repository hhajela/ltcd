#include <string>
#include <iostream>

using namespace std;

class Solution
{
	public:
		string GetMaximumTime(const string & input)
		{
			string strMaxTime = input;

			//hours tens digit is 2 if minutes <= 3 else 1
			//hours ones digit is 9 if hours <=1 else 3
			//

			if (strMaxTime[0] == '?')
			{
				if (strMaxTime[1] == '?')
				{
					strMaxTime[0] = '2';
					strMaxTime[1] = '3';
				}
				else
				{
					if (strMaxTime[1]-'0' <= '3'-'0')
						strMaxTime[0] = '2';
					else
						strMaxTime[0] = '1';
				}
			}
			else
			{
				if (strMaxTime[1] == '?')
				{
					if (strMaxTime[0]-'0' <= '1'-'0')
						strMaxTime[1] = '9';
					else
						strMaxTime[1] = '3';
				}
			}


			//minutes ones digit is max 9, tens max 5 independent of each other

			if (strMaxTime[3] == '?')
				strMaxTime[3] = '5';
			
			if (strMaxTime[4] == '?')
				strMaxTime[4] = '9';

			return strMaxTime;
		}
};

int main()
{
  Solution S1;
  string strInput = "?4:5?";
  cout << S1.GetMaximumTime(strInput) << endl;

  strInput = "23:5?";
  cout << S1.GetMaximumTime(strInput) << endl;

  strInput = "2?:22";
  cout << S1.GetMaximumTime(strInput) << endl;

  strInput = "0?:??";
  cout << S1.GetMaximumTime(strInput) << endl;

  strInput = "??:??";
  cout << S1.GetMaximumTime(strInput) << endl;

  strInput = "?4:2?";
  cout << S1.GetMaximumTime(strInput) << endl;

  return 0;
}
