#include <iostream>
#include <stack>
//#include <iostream>
//#include <iostream>

using namespace std;

struct TreeNode
{
	TreeNode * left;
	TreeNode * right;
	int val;
};

class Solution
{
	public:

	bool IsValidBST(TreeNode * root)
	{
		stack<TreeNode *> stTraversal;
		bool first= true;
		int val = 0;
		TreeNode * temp = root;

		while(temp!=NULL || !stTraversal.empty())
		{
			while(temp != NULL)
			{
				stTraversal.push(temp);
				temp = temp->left;
			}

			temp = stTraversal.top();
			stTraversal.pop();

			if (first || temp->val > val)
			{
				first = false;
				val = temp->val;
			}
			else
				return false;

			temp = temp->right;
		}

		return true;
	}
};


int main()
{
	Solution S1;
	TreeNode leftleft = {NULL,NULL,4};
	TreeNode right = {NULL,NULL,3};
	TreeNode left = {&leftleft,NULL,0};

	TreeNode root = {&left,&right, 1};

	cout<<S1.IsValidBST(&root);
	return 0;
}
