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

TreeNode * last_right(TreeNode * root){

    while(root->right){
        root = root->right;
    }

    return root;
}

TreeNode * helper(TreeNode * root){

    if(!root->left) return root->right;
    else if(!root->right) return root->left;

    else{
        TreeNode * right = root->right;
        TreeNode * last_right_in_left = last_right(root->left);

        last_right_in_left->right = right;

        return root->left;
    }

}

TreeNode * delete_node(TreeNode * root, int key){

    if(!root) return root;

    if(root->val == key) return helper(root);

    TreeNode * dummy = root;

    while(!root){
        if(key > root->val){

            if(root->right != NULL && root->right->val == key){
                root->right = helper(root->right);
            }

            else root = root->right;
        }

        else{

            if(root->left != NULL && root->left->val == key){
                root->left = helper(root->left);
            }

            else root = root->left;            
        }
    }

    return dummy;

}