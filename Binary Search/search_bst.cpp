#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode *searchBST(TreeNode *root, int val) {
    if(!root)
        return NULL;
    if(root->val == val)
        return root;
    if(val < root->val)
        return searchBST(root->left, val);
    else    
        return searchBST(root->right, val);
}