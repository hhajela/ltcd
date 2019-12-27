#include <iostream>

using namespace std;

int NumberOf1Bits(int num)
{
	int counter = 0;
	while(num>0)
	{
		num &= num-1;
		counter++;
	}
	return counter;
}


int main()
{
	int num = 7;
	cout << "NUmber of set bits " << NumberOf1Bits(num) << endl;
	num = 4;
	cout << "NUmber of set bits " << NumberOf1Bits(num) << endl;
	num = 3;
	cout << "NUmber of set bits " << NumberOf1Bits(num) << endl;
	num = 12;
	cout << "NUmber of set bits " << NumberOf1Bits(num) << endl;

	return 0;
}
