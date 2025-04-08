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


struct bst {
    bool isBST;
    int size;
    int min, max;
};

class Solution{
    public:
        int size;

        bst find(TreeNode *root) {
        if(!root) 
            return {true, 0, INT_MAX, INT_MIN};

        if(!root->left && !root->right) 
            return {true, 1, root->val, root->val};
           
        bst left = find(root->left);
        bst right = find(root->right);
        
        if(left.isBST && right.isBST) {
            if(root->val > left.max && root->val < right.min) {
                
                int min_val = left.min;
                int max_val = right.max;

                if(min_val == INT_MAX)
                    min_val = root->val;
                if(max_val == INT_MIN)
                    max_val = root->val;
                
                return {1, left.size + right.size + 1, min_val, max_val};
            }
        }
        return {0, max(left.size, right.size), 0, 0};
    }
    
    int largestBst(TreeNode *root)
    {
        bst b = find(root);
        return b.size;
    }
};