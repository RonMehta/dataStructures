#include <iostream>
/**
* Definition for a binary tree node.
*/
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 bool isValidBST1(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
	 if (!root) return true;
	 if (minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
		 return false;
	 return isValidBST1(root->left, minNode, root) && isValidBST1(root->right, root, maxNode);
 }
 bool isValidBST(TreeNode* root) {
	 return isValidBST1(root, NULL, NULL);
 }


void main()
{
	TreeNode *childroot = new TreeNode(1);
	TreeNode *root = new TreeNode(1);
	root->left = childroot;
	isValidBST(root);

}
