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

vector<int> preorder(TreeNode *node)
{
    vector<int> res;

    if (node == NULL)
        return res;

    res.push_back(node->val);

    vector<int> left = preorder(node->left);
    vector<int> right = preorder(node->right);

    res.insert(res.end(), left.begin(), left.end());
    res.insert(res.end(), right.begin(), right.end());
    return res;
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> res;

    if (root == NULL)
        return res;

    vector<int> left = inorderTraversal(root->left);
    res.insert(res.end(), left.begin(), left.end());

    res.push_back(root->val);

    vector<int> right = inorderTraversal(root->right);
    res.insert(res.end(), right.begin(), right.end());
    return res;
}

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> res;

    if (root == NULL)
        return res;

    vector<int> left = postorderTraversal(root->left);
    res.insert(res.end(), left.begin(), left.end());


    vector<int> right = postorderTraversal(root->right);
    res.insert(res.end(), right.begin(), right.end());

    res.push_back(root->val);

    return res;
}