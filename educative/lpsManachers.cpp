#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

string AddSeparators(const string & strInput)
{
    string strRet(2*strInput.length()+1,'|');

    for(int i =0; i<strInput.length(); i++)
    	strRet[i*2+1] = strInput[i];

    return strRet;
}

string LPS(const string & strInput)
{
    //first add separators
    string strTemp = AddSeparators(strInput);

    // abcdedcba
    // if you are aware of the length of a reference palindrome, you can use that to infer length of mirror image palindromes

    vector<int> vecLengths(strTemp.length(),0); //length of palindromes centered at every possible position

    int curCenter = 0; //reference center
    int i =1; //center of next palindrome to look at
    int r= 0; //right bound of the current palindrome
    int m,n; //walking indices
    m=n=0;

    //calculate maximum palindrome length for every possible center
    for(i =1; i<vecLengths.size(); i++)
    {
        //if the center of the palindrome is within the bounds of the current reference palindrome
        if(i <= r)
	{
		//try to calculate the length of the mirror image palindrome of i
		//if that is within the bounds of the reference palindrome, then so is the one at i

            int i_ = 2*curCenter - i; //mirror image of i around curCenter

	    if(vecLengths[i_] < r-i-1) //length of palindrome at i within the distance from i to bound-1
	    {
		    vecLengths[i] = vecLengths[i_];
		    m= -1; //set to -1 to prevent walking
	    }
	    else
	    {
		    //palindrome at i is at least as long as the bound
		    vecLengths[i] = r-i;

		    //initialize walking indices to check how much further ahead it goes
		    n=r+1;
		    m = 2*i -n;
	    }
        }
        else
        {
            //i is not within the bounds of the reference palindrome
            //try to calculate length normally
            vecLengths[i] =0;
            n = i+1;
            m = i-1;
        }

        //extend the ends of the palindrome till a mismatch or end of array
        while(m>=0 && n<strTemp.length() && strTemp[m]==strTemp[n])
        {
            vecLengths[i]++;
            m--;
            n++;
        }

        //if the right bound of the palindrome at i is after than the current reference, make it the current
        if((vecLengths[i]+i) > r)
        {
                curCenter = i;
                r = vecLengths[i]+i;
        }
    }

    int nMax= 0;
    //find longest
    for(int j =0; j <vecLengths.size(); j++)
    {
            if (vecLengths[j]>vecLengths[nMax])
                    nMax = j;
    }
    
    string strLPS = strTemp.substr(nMax-vecLengths[nMax],2*vecLengths[nMax]+1);

    //remove separators
    string strRet = "";
    for(int i=1; i<strLPS.length(); i+=2)
	    strRet += strLPS[i];

    return strRet;
}


int main()
{
    string strInput = "adccdbaegdh";
    printf("Maximum length palindrome is %s \n", LPS(strInput).c_str());    
    return 0;
}


