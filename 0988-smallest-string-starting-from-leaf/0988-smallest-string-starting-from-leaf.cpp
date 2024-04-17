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
    void f(TreeNode* root , string res , string& ans)
    {
        if(root == nullptr)
            return;
        if(root -> left ==  nullptr && root -> right == nullptr)
        {
            res+=char(root->val+'a');
            reverse(begin(res), end(res));
            if(ans.size()==0)
              ans=res;
            else
              ans=min(ans,res);
            reverse(begin(res), end(res));
            res.pop_back();
            return ;
        }
        f(root -> left , res + char(root -> val + 'a'), ans);
        f(root -> right , res + char(root -> val + 'a'), ans);
    }
    string smallestFromLeaf(TreeNode* root) 
    {
       string ans = "";
       f(root , "" , ans);
       return ans;
    }
};