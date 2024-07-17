/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int,int> mp;
    TreeNode* f(TreeNode*root,vector<TreeNode*>& ans)
    {
        if(root==nullptr)
            return root;
        if(mp.find(root->val)!=mp.end())
        {
           root->left=f(root->left,ans);
           root->right=f(root->right,ans);  
           if(root->left)
               ans.push_back(root->left);
           if(root->right)
               ans.push_back(root->right);
           return nullptr;
        }
        else
        {
           root->left=f(root->left,ans);
           root->right=f(root->right,ans);
           return root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& td) 
    {
       mp.clear();
       for(auto x: td)
           mp[x]+=1;
       vector<TreeNode*> ans;
       TreeNode* m=f(root,ans);
       if(m)
           ans.push_back(m);
       return ans;
    }
};