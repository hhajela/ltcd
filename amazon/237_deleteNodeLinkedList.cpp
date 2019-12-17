#include <iostream>

using namespace std;

struct ListNode
{
	ListNode * next;
	int val;
};

void DeleteNode(ListNode * node)
{
	node->val = (node->next)->val;

	ListNode * temp = node->next;
	node->next = (node->next)->next;

	delete temp;
}


int main()
{
	int size;
	cin >> size;

	int k;
	cin >> k;

	ListNode * head = NULL;
	ListNode * temp = NULL;
	ListNode * temp2 = NULL;

	for (int i=0; i< size; i++)
	{
		int tempValue;
		cin >> tempValue;
		if (temp == NULL)
			head = temp = new ListNode {NULL,tempValue};
		else
		{
			temp->next = new ListNode {NULL, tempValue};
			temp = temp->next;
		}


		if (k==tempValue) temp2 = temp;
	}
	

	DeleteNode(temp2);

	temp = head;
	while(temp != NULL)
	{
		cout << temp->val << endl;
		temp = temp->next;
	}

}

