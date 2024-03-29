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
    vector<int> v;
    void f(TreeNode* root)
    {
        if(root==nullptr)
            return ;
        f(root->left);
        v.push_back(root->val);
        f(root->right);
    }
    int getMinimumDifference(TreeNode* root) 
    {
        v.clear();
        f(root);
        int ans=1e9;
        for(int i=0;i<v.size()-1;i++)
            ans=min(ans,abs(v[i]-v[i+1]));
        return ans;
        
    }
};