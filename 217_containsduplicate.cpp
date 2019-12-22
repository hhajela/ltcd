#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool ContainsDuplicate(vector<int> vecNums)
{
	//iterate thru numbers, add them to a set
	//if theres a dupe return true
	
	if(vecNums.size() <=1) return false;
	unordered_set<int> setValues;

	for(auto & num: vecNums)
	{
		if(setValues.find(num) != setValues.end())
			return true;

		setValues.insert(num);
	}

	return false;
}

int main()
{
	vector<int> vecNum = {1,3,4,5,6};

	cout << "Contains duplicates : " << (ContainsDuplicate(vecNum)?"true":"false") << endl;
	return 0;

}
