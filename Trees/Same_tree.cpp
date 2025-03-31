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

bool identical(TreeNode *p, TreeNode *q) {

    if(!p && !q)
        return true;

    if(!p || !q)
        return false;

    if(p->val != q->val)
        return false;

    return identical(p->left, q->left) && identical(p->right, q->right);
}