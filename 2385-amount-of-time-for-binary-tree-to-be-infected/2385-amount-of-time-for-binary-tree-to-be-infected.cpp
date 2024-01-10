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
    unordered_map<int,vector<int>> adj;
    void build(TreeNode* root)
    {
       if(root==nullptr)
           return ;
        if(root->left)
        {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right)
        {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        build(root->left);
        build(root->right);
    }
    int amountOfTime(TreeNode* root, int start)
    {
        build(root);
        unordered_map<int,int> vis,dis;
        queue<int> q;
        q.push(start);
        dis[start]=0;
        vis[start]=1;
        while(q.size()>0)
        {
            auto u=q.front();
            q.pop();
            for(auto v: adj[u])
            {
                if(vis.find(v)==vis.end())
                {
                    vis[v]=1;
                    dis[v]=dis[u]+1;
                    q.push(v);
                }
            }
        }
        int maxi=0;
        for(auto t: dis)
            maxi=max(maxi,t.second);
        return maxi;
    }
};