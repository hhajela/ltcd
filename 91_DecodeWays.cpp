#include <iostream>
#include <vector>


using namespace std;


int DecodeWays(const string & strMessage)
{
	if (strMessage.empty()) return 0;

	//can decode substrign upto ith position if there is a valid string decodign at i-1 or i-2
	//and ith or ith+i-1th characters comprise valid encoded letters
	//for empty string 
	int waysMinusOne = 1;
	int waysMinusTwo = 0;

	for(int i=0; i<strMessage.length(); i++)
	{
		int encodingValue = (strMessage[i]-'0') + (i>0?(strMessage[i-1]-'0')*10:0);

		int currentWays = 0;
		//no of ways if valid decoding at i-1 and this character is a valid letter
		if (strMessage[i] <= '9' && strMessage[i] >= '1')
			currentWays = waysMinusOne;
		
		//no of ways if valid decoding at i-2 and this and the last character comprise of a valid two digit encoded letter
		//only count the cases where two letter decoding
		if (encodingValue >= 10 && encodingValue <= 26)
			currentWays += waysMinusTwo;


		waysMinusTwo = waysMinusOne;
		waysMinusOne = currentWays;
	}

	return waysMinusOne;
}	

int main()
{
	string strMessage;
	getline(cin, strMessage);

	cout << "Number of possible ways of decoding string are " << DecodeWays(strMessage) << endl;
}

