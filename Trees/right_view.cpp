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

class solution{
    public:
    vector<int> rightSideView(TreeNode* root) {

        vector <int> res;
        func(root, 0, res);
        return res;

        
    }

    public:
    void func(TreeNode * root, int level , vector<int> & res){
    
    if(!root) return ;
    if(level == res.size()) res.push_back(root->val);

    func(root->right, level+1, res);
    func(root->left, level+1, res);
    }
};
