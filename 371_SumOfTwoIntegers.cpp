#include <iostream>
#include <string>

using namespace std;


int AddTwoIntegers(int a, int b)
{
	//implement a full adder
	
	//extract digits one by one
	
	//trivial cases
	if(a==0) return b;
	if (b==0) return a;

	int result = 0;
	int counter = 0;
	bool curA= false, curB= false, carry=false;

	do
	{
		//extract the cleast significant digit
		curA = a&1;
		curB = b&1;

		//compute sum and carry
		result |= (curA ^ curB ^ carry)<<counter;
		carry = ((curA^curB)&carry) | (curA&curB);

		a>>=1;
		b>>=1;
		counter++;
	}
	while((carry || a || b) && counter < (sizeof(int)*8));

	return result;
}


int main()
{
	cout << "Sum of Two integers : " << AddTwoIntegers(-1,-3) << endl;
	cout << "Sum of Two integers : " << AddTwoIntegers(-2,2) << endl;	
	cout << "Sum of Two integers : " << AddTwoIntegers(-3,4) << endl;
	return 0;
}
