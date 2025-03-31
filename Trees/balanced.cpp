
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

int checkHeight(TreeNode* root) {
    if (!root) return 0; 

    int left = checkHeight(root->left); 
    if (left == -1) return -1; 

    int right = checkHeight(root->right);
    if (right == -1) return -1; 

    if (abs(left - right) > 1) return -1;

    return max(left, right) + 1; 
}

bool isBalanced(TreeNode* root) {
    return checkHeight(root) != -1; 
}