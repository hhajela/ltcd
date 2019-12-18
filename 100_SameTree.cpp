#include <iostream>


struct TreeNode
{
	TreeNode * left;
	TreeNode * right;
	int val;
};


bool SameTree(TreeNode * root1, TreeNode * root2)
{
	if(root1==NULL && root2 == NULL) return true;

	if(root1==NULL || root2==NULL) return false;

	return (root1->val==root2->val && SameTree(root1->left,root2->left) && SameTree(root1->right,root2->right));
}

int main()
{
	

	return 0;
}
