#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool ContainsDuplicatesWithinDistance(vector<int> vecNums, int threshold)
{
	//iterate thru the vector, add unseen values to a map
	//for seen values measure distance from last seen position
	//if within threshold then reutrn true else update last seen
	//
	
	unordered_map<int,unsigned int> mapPositions;
	
	for(int i=0;i<vecNums.size(); i++)
	{
		if(mapPositions.find(vecNums[i]) != mapPositions.end())
			if(i-mapPositions[vecNums[i]] <= threshold)
				return true;

		mapPositions[vecNums[i]] = i;
	}

	return false;
}


int main()
{
	vector<int> vecNums = {1,3,4,5,1,3,4,5};

	cout << "Duplicates within 3 positions : " << (ContainsDuplicatesWithinDistance(vecNums,3)?"true":"false") << endl;

	return 0;
}
