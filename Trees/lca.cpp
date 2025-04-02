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



class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            
            if(root == NULL || root->val == p->val || root->val == q->val) return root;

            TreeNode * left = lowestCommonAncestor(root->left, p , q);
            TreeNode * right = lowestCommonAncestor(root->right, p , q);

            if(!left) return right;
            if(!right) return left;
            else return root;

        }
    };