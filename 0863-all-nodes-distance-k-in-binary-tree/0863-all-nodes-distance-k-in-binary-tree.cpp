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
    vector<int> adj[100001];
    int vis[100001];
    unordered_map<TreeNode*,int> mp;
    int k=0;
    void build(TreeNode* root)
    {
        if(root==nullptr)
            return ;
        if(mp.find(root)==mp.end())
                mp[root]=k++;
        if(root->left!=nullptr)
        {
            if(mp.find(root->left)==mp.end())
                mp[root->left]=k++;
            adj[mp[root]].push_back(mp[root->left]);
            adj[mp[root->left]].push_back(mp[root]);
            
        }
        if(root->right)
        {
            if(mp.find(root->right)==mp.end())
                mp[root->right]=k++;
            adj[mp[root]].push_back(mp[root->right]);
            adj[mp[root->right]].push_back(mp[root]);
            
        }
        build(root->left);
        build(root->right);
            
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) 
    {    k=0;
         build(root);  
        int x=mp[target];
       unordered_map<int,TreeNode*> muth;
        for(auto t=mp.begin();t!=mp.end();t++)
            muth[t->second]=t->first;
       queue<int> q;
     q.push(mp[target]);
     vis[mp[target]]=1;
     int tmp=0;
     vector<TreeNode*> ps;
     while(q.size()>0)
     {
         int sz=q.size();
         while(sz--)
         {
             if(tmp==K)
             {
                int x=q.front();
                 q.pop();
                 ps.push_back(muth[x]);
                 for(auto t: adj[x])
                 {
                     if(vis[t]==0)
                        { q.push(t);vis[t]=1;}
                 }
             }
             else
             {
                 int x=q.front();
                 q.pop();
                 //ps.push_back(muth[x]);
                 for(auto t: adj[x])
                 {
                     if(vis[t]==0)
                         {q.push(t);vis[t]=1;}
                 }
             }
         }
         if(tmp==K)
             break;
         tmp++;
     }
     vector<int> ans;
     for(auto t: ps)
         ans.push_back(t->val);
     return ans;
     
    }
};