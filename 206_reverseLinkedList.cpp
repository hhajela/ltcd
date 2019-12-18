#include <iostream>

using namespace std;

struct ListNode
{
	ListNode * next;
	int val;
};

ListNode * ReverseList(ListNode * head, bool iterative)
{

	//iterative way
	
	ListNode * prev = NULL;
	ListNode * cur = head;

	ListNode * temp;

	while(cur != NULL)
	{
		temp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = temp;
	}


	return prev;
}

ListNode * ReverseList(ListNode * head)
{
	//recursive way
	//
	
	if (head==NULL || head->next == NULL) return head;

	ListNode * rest = ReverseList(head->next);

	(head->next)->next = head;
	head->next = NULL;

	return rest;
}


int main()
{
	int sz;
	cin >> sz;

	ListNode * head= NULL;
	ListNode * temp = NULL;
	for(int i=0; i<sz; i++)
	{
		int val;
		cin >> val;
		if (head==NULL)
			head = temp = new ListNode {NULL, val};
		else
		{
			temp->next = new ListNode {NULL, val};
			temp = temp->next;
		}

	}

	head = ReverseList(head);

	temp = head;
	while(temp != NULL)
	{
		cout << temp->val << endl;
		temp = temp->next;
	}

	return 0;
}
