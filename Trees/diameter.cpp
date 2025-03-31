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

int height(TreeNode *root, int &maxi) {
    if (!root)
        return 0;

    int left = height(root->left, maxi);  
    int right = height(root->right, maxi); 

    maxi = max(maxi, left + right); 

    return max(left, right) + 1; 
}

int diameter(TreeNode *root) {
    int maxi = 0; 
    height(root, maxi); 
    return maxi;
}