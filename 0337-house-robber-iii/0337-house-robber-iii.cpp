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
    map<pair<TreeNode*,int>,int> mp;
    // nice dp on trees
    int f(TreeNode* root,int liya)
    {
       if(root==nullptr)
           return 0;
        if(mp.find({root,liya})!=mp.end())
            return mp[{root,liya}];
        int ans=0;
       if(liya==1)
       {
          ans+=f(root->left,liya^1);
          ans+=f(root->right,liya^1);
       }
       else
       {
           int ans1=root->val;
           ans1+=f(root->left,1);
           ans1+=f(root->right,1);
           int ans2=0;
           ans2+=f(root->left,0);
           ans2+=f(root->right,0);
           ans=max(ans1,ans2);
       }
        return mp[{root,liya}]=ans;
    }
    int rob(TreeNode* root) 
    {
        int ans=f(root,0);
        return ans;
    }
};