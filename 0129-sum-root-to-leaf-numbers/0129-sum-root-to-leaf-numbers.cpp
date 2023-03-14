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
    int ans;
    void f(TreeNode* root,string str)
    {
        if(root==nullptr)
            return ;
        if(root->left==nullptr & root->right==nullptr)
        {
            str+=to_string(root->val);
            ans+=stoi(str);
            str.pop_back();
            return ;
        }
        f(root->left,str+to_string(root->val));
        f(root->right,str+to_string(root->val));
    }
    int sumNumbers(TreeNode* root) 
    {   ans=0;
        string str;
        f(root,str);
        return ans;
    }
};