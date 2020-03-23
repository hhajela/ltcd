#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node
{
	int val;
	vector<Node *> nbors;

	Node(int val) : val(val) {}

	Node(int val, const vector<Node *>& nbors) : val(val), nbors(nbors) {} 
};

Node * CopyGraph(Node * start)
{
	if (start==NULL) return NULL;

	//do BFS to traverse, use unordered_map to store new nodes
	unordered_map<unsigned char, Node *> mapNodes;
	queue<Node *> nodeQ;

	//copy first element
	mapNodes[1] = new Node(start->val);

	//push for dsicovery
	nodeQ.push(start);

	while(!nodeQ.empty())
	{
		Node * front = nodeQ.front();
		int frontVal = front->val;
		nodeQ.pop();

		for(auto nborNode : front->nbors)
		{
			int nborVal = nborNode->val;
			//init nbor nodes if required and push for discovery
			if (mapNodes.find(nborVal) == mapNodes.end())
			{
				mapNodes[nborVal] = new Node(nborVal);
				nodeQ.push(nborNode);
			}

			//set pointer
			mapNodes[frontVal]->nbors.push_back(mapNodes[nborVal]);
		}
	}

	return mapNodes[1];
}


void Traverse(Node * start)
{
	if (start== NULL)
		return; 
	//do BFS
	queue<Node *> nodeQ;
	bool bVisited[100] = {false};
	bVisited[0] = true;
	nodeQ.push(start);

	while(!nodeQ.empty())
	{
		//get front element
		Node * front = nodeQ.front();
		nodeQ.pop();

		cout << front->val <<  " " << front << " ";
		for(auto nbor : front->nbors)
		{
			if (bVisited[nbor->val -1])
				continue;

			nodeQ.push(nbor);

			bVisited[nbor->val -1] = true;
		}
	}
	cout << endl;
}

int main()
{
	Node * n = new Node(1);
	Node * n1 = new Node(2);
	Node * n2 = new Node (3);
	Node * n3 = new Node(4);
	n->nbors.push_back(n1);
	n->nbors.push_back(n3);

	n1->nbors.push_back(n);
	n1->nbors.push_back(n2);

	n2->nbors.push_back(n1);
	n2->nbors.push_back(n3);

	n3->nbors.push_back(n);
	n3->nbors.push_back(n2);

	Traverse(n);

	Node * nCopy = CopyGraph(n);

	Traverse(nCopy);
	
	return 0;
}
