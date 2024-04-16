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
    void f(TreeNode* root , string res , int& val)
    {
        if(root == nullptr)
            return ;
        if(root -> left == nullptr && root -> right == nullptr)
        {
            res+=char(root->val+'0');
            val += stoi(res);
            res.pop_back();
            return ;
        }
        f(root -> left , res+char(root->val + '0') , val);
        f(root -> right , res+char(root->val + '0') , val);
        
    }
    int sumNumbers(TreeNode* root) 
    {
        if(root == nullptr)
            return 0;
        int val = 0;
        f(root , "" , val);
        return val;
    }
};