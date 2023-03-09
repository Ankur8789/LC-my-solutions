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
    bool check(vector<int>& freq)
    {
       int cc=0;
        for(int i=0;i<10;i++)
        {
            if(freq[i]&1)
                cc++;
        }
        if(cc<=1)
            return true;
        return false;
        
    }
    int f(TreeNode* root,vector<int>& freq){
        if(root==NULL)
            return 0;
        if(root->left==NULL&&root->right==NULL)
        {
            freq[root->val]++;
            int res;
            if(check(freq))
            {
                 res=1;
            }
            else
                res=0;
            freq[root->val]--;
            return res;
        }
        freq[root->val]++;
        int leftside=f(root->left,freq);
        int rightside=f(root->right,freq);
        freq[root->val]--;
        return leftside+rightside;
        
    }
    int pseudoPalindromicPaths (TreeNode* root)
    {
        int ans;
        vector<int> freq(10);
        ans=f(root,freq);
        return ans;
        
    }
};