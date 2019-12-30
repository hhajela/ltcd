#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>


using namespace std;

struct HeapNode
{
	int value;
	int listIndex;
};

class MinComparator
{
	public:

	bool operator()(const HeapNode & a, const HeapNode & b )
	{
		return a.value > b.value;
	}
};


class Soln
{
	public:

	vector<int> MergeKSortedLists(vector<vector<int>> vecLists)
	{
		//at every point, pick the smallest number from the remaining elements of all the lists, add it to result

		//to keep track of the smallest element, use a heap
		vector<int> vecResult;

		if (vecLists.empty()) return vecResult;

		//remove empty lists
		auto it = vecLists.begin();
		while(it != vecLists.end())
		{
			if (it->empty())
			{
				it = vecLists.erase(it);
			}
			else
				it++;

		}

		//init heap with the first element of all the lists
		priority_queue<HeapNode, vector<HeapNode>, MinComparator> minQ;

		for(int i = 0; i<vecLists.size(); i++)
			minQ.push(HeapNode {vecLists[i][0], i});

		vector<int> vecCurrentIndices(vecLists.size(),0);

		//while heap is not empty, get smallest element, add to result list, move the corresponding list ahead
		while(!minQ.empty())
		{
			//get smallest element
			HeapNode smallest = minQ.top();
			minQ.pop();

			//add to result
			vecResult.push_back(smallest.value);

			//move corresponding list ahead if this was not the last element
			vector<int> & corrList = vecLists[smallest.listIndex];
			int & curPos = vecCurrentIndices[smallest.listIndex];

			printf("Element removed, list index [%d,%d] \n", smallest.value, smallest.listIndex);
			if (curPos != corrList.size()-1)
			{
				//move list ahead
				curPos++;
				
				//add next element from this list to heap
				minQ.push(HeapNode {corrList[curPos], smallest.listIndex } );
			}

		}

		return vecResult;
	}

	
};


int main()
{
	Soln S1;

	vector<int> vec1 = {1,3,4,6,7,9};
	vector<int> vec2 = {-1,0,2,3,11};
	vector<int> vec4;
	vector<int> vec3 = {-9,6,10,14,15,27};

	vector<int> vecResult = S1.MergeKSortedLists(vector<vector<int>> {vec1,vec2,vec3, vec4});

	for (auto & val: vecResult) cout << val << " ";

	cout << endl;

	return 0;
}
