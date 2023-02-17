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
    vector<int> temp;
    void f(TreeNode* root)
    {
        if(root==nullptr)
            return ;
        temp.push_back(root->val);
        f(root->left);
        f(root->right);
    }
    int minDiffInBST(TreeNode* root) 
    {
       
        f(root);
        sort(temp.begin(),temp.end());
        int ans=1e5;
        for(int i=0;i<temp.size()-1;i++)
        {
            ans=min(ans,temp[i+1]-temp[i]);
        }
        return ans;
    }
};