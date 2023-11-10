class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_map<int,int> ideg,vis;
    void dfs(int u,vector<int>& res)
    {
        vis[u]=1;
        res.push_back(u);
        for(auto t: adj[u])
        {
            if(vis.find(t)==vis.end())
            {
                dfs(t,res);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjp) 
    {
        int n=adjp.size();
        n++;
        for(auto t: adjp)
        {
            int u=t[0];
            int v=t[1];
            ideg[u]++;
            ideg[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> res;
        for(auto t:ideg)
        {
            if(t.second==1)
            {
                dfs(t.first,res);
                break;
            }
        }
        return res;
        
    }
};