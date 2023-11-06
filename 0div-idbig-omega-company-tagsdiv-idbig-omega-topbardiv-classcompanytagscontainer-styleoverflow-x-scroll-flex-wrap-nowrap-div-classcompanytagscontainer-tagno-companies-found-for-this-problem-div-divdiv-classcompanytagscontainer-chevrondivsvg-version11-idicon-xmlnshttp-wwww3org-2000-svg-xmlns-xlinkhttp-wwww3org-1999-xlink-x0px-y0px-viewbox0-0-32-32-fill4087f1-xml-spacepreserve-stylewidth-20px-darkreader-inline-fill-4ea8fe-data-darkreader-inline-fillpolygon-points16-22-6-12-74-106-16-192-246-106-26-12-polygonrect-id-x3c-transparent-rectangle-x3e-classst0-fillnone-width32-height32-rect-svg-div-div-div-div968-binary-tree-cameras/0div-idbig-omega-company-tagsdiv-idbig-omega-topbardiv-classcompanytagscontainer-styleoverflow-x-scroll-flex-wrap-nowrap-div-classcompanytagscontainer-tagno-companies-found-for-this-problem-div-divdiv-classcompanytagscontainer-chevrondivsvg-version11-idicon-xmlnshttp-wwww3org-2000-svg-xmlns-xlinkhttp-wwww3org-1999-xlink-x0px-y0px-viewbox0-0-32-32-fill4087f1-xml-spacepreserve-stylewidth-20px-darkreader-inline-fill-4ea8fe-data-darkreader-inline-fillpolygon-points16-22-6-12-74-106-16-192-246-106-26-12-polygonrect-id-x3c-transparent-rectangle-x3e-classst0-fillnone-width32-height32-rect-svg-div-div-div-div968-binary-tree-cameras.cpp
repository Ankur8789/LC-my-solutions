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
    map<tuple<TreeNode*,int,int>,int> dp;
    int f(TreeNode* root,int parcamera,int parunder)
    {
       if(root==nullptr)
       {
           if(parunder)
               return 0;
           else
               return 1e5;
            
       }
       if(dp.find({root,parcamera,parunder})!=dp.end())
           return dp[{root,parcamera,parunder}];
       int ans=1e5;
       if(parcamera==-1)
       {
         // khud hi laga do
         ans=min(ans,1+f(root->left,1,1)+f(root->right,1,1));
         //left kar dega
         ans=min(ans,f(root->left,0,0)+f(root->right,0,1));
         // right kar dega
         ans=min(ans,f(root->left,0,1)+f(root->right,0,0));
         return dp[{root,parcamera,parunder}]=ans;
          
       }
       if(parcamera)
       {
           ans=min(ans,1+f(root->left,1,1)+f(root->right,1,1));
           ans=min(ans,f(root->left,0,1)+f(root->right,0,1));
       }
       else
       {
           if(parunder)
           {
              // khud hi laga do
              ans=min(ans,1+f(root->left,1,1)+f(root->right,1,1));
              // left kar dega
              ans=min(ans,f(root->left,0,0)+f(root->right,0,1));
              // right kar dega
              ans=min(ans,f(root->left,0,1)+f(root->right,0,0));
           }
           else
               ans=min(ans,1+f(root->left,1,1)+f(root->right,1,1));
       }
       return dp[{root,parcamera,parunder}]=ans;
       
    }
    int minCameraCover(TreeNode* root) 
    {
       int ans=f(root,-1,1);
       return ans;
    }
};