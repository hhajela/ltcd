#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>

//introducing memoization




using namespace std;

class Soln
{
	vector<int> vecSubs;

int Fibonacci(int i)
{
	if (i<0) return 0;
	//check if present in subsolutions
	if(vecSubs[i] != -1)
	{
		cout << i << " already known" << endl;
		return vecSubs[i];
	}
	cout << "have to compute for " << i << endl;

	vecSubs[i] = Fibonacci(i-1)+Fibonacci(i-2);
	return vecSubs[i];

}

public:

int FibonacciWithMemoization(int n)
{
	vecSubs = vector<int>(n+1,-1);
	
	vecSubs[0]= 0;
	vecSubs[1] =1;

	return Fibonacci(n);
}

int FibonacciBest(int n)
{
	//basic cases
	if(n<2) return n;

	//nth value is twice of n-1 and n-2
	int minusOne = 1;
	int minusTwo = 0;
	int cur;

	for(int i =2; i<n; i++)
	{
		cur=minusOne+minusTwo;
		minusTwo = minusOne;
		minusOne = cur;
	}

	return cur;
}

};

int main(int argc, char ** argv)
{
	int n = argc>1?atoi(argv[1]):4;
	printf("%dth fibonacci number is %d\n", n, Soln().FibonacciBest(n));
	return 0;
}

