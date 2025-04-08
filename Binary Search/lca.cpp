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

TreeNode *lca(TreeNode *root, int p, int q) {

    if(!root) return NULL;
    int cur = root->val;

    if(cur < p && cur < q)
        return lca(root->right, p, q);

    if(cur > p && cur > q)
        return lca(root->left, p, q);

        return root;
}