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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) 
    {
       map<int,TreeNode*> mp;
       map<int,int> ideg;
       for(auto x: desc)
       {
           int u=x[0];
           int v=x[1];
           TreeNode* nw=new TreeNode();
           if(mp.find(u)==mp.end())
               mp[u]=nw;
           else
               nw=mp[u];
           nw->val=u;
           if(x[2])
           {
               TreeNode* child=new TreeNode();
               if(mp.find(v)==mp.end())
                   mp[v]=child;
               else
                   child=mp[v];
               child->val=v;
               nw->left=child;
           }
           else
           {
               TreeNode* child=new TreeNode();
               if(mp.find(v)==mp.end())
                   mp[v]=child;
               else
                   child=mp[v];
               child->val=v;
               nw->right=child;
           }
           ideg[u]+=0;
           ideg[v]+=1;
       }
       TreeNode* ans=new TreeNode();
       for(auto x: ideg)
       {
           if(x.second==0)
           {
               ans=mp[x.first];
               break;
           }
       }
       return ans;
    }
};