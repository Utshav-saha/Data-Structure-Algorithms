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

int height(TreeNode *root) {

    if(!root)
        return 0;


    int left = height(root->left);
    int right = height(root->right);

    return max(left, right) + 1;
}