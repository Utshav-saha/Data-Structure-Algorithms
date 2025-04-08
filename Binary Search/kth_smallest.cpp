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

int k_th_smallest(TreeNode *root, int k) {
    stack < TreeNode *> s;
    
    while(!s.empty() || root) {
         while(root) {
            s.push(root);
            root = root->left;
         }
         root = s.top();
         s.pop();
         if(--k == 0) return root->val;
         root = root->right;
    }
    return -1;
 }