/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int,vector<int>> adj;
    void build(TreeNode* root)
    {
        if(root==nullptr)
            return;
        if(root->left!=nullptr)
        {
            adj[root->left->val].push_back(root->val);
            adj[root->val].push_back(root->left->val);
        }
        if(root->right!=nullptr)
        {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        build(root->left);
        build(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        build(root);
        unordered_map<int,int> vis,dis;
        queue<int> q;
        q.push(target->val);
        vis[target->val]=1;
        dis[target->val]=0;
        while(q.size()>0)
        {
           int x=q.front();
            q.pop();
           for(auto t: adj[x])
           {
               if(vis.find(t)==vis.end())
               {
                   dis[t]=dis[x]+1;
                   vis[t]=1;
                   q.push(t);
               }
           }
        }
        vector<int> ans;
        for(auto t: dis)
        {
            cout<<t.first<<" "<<t.second<<endl;
            if(t.second==k)
                ans.push_back(t.first);
        }
        return ans;
    }
};