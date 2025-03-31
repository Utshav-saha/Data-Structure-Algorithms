#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public :
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }

    
};

int main()
{
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
}