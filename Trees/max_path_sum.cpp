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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN; 
        func(root, maxi);
        return maxi;
    }

private:
    int func(TreeNode* node, int &maxi) {
        if (node == NULL) return 0;

        int leftsum = max(0, func(node->left, maxi));
        int rightsum = max(0, func(node->right, maxi));

        maxi = max(maxi, node->val + leftsum + rightsum);

        return node->val + max(leftsum, rightsum);
    }
};