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

TreeNode *insert(TreeNode *root, int val)
{
    if (!root)
        return new TreeNode(val);

    TreeNode *cur = root;

    while (true)
    {
        if (cur->val < val)
        {
            if (!cur->right)
            {
                cur->right = new TreeNode(val);
                break;
            }

            else
                cur = cur->right;
        }

        else
        {

            if (!cur->left)
            {
                cur->left = new TreeNode(val);
                break;
            }

            else
                cur = cur->left;
        }
    }

    return root;
}