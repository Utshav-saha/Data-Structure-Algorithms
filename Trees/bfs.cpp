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

vector<vector< int > > levelOrder(TreeNode *root) {
    
    vector<vector< int > > ans;

    if(!root)
        return ans;
    
    queue<TreeNode*> q;
    q.push(root); 

    while(!q.empty()) {

       int n = q.size();
       vector<int> level;

       while(n--) {
            TreeNode *front = q.front();
            q.pop();

            level.push_back(front->val);

            if(front->left)
                q.push(front->left);
                
            if(front->right)
                q.push(front->right);
       }
       ans.push_back(level);
    }
    return ans;
}