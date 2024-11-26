class Solution {
public:
    unordered_map<int,vector<int>> adj;
    void dfs(int u,int& cnt,unordered_map<int,int>& vis)
    {
        vis[u]=1;
        cnt++;
        for(auto v: adj[u])
        {
            if(vis.find(v)==vis.end())
            {
                dfs(v,cnt,vis);
            }
        }
    }
    int findChampion(int n, vector<vector<int>>& edges) 
    {
         for(auto t: edges)
         {
             int u=t[0];
             int v=t[1];
             adj[u].push_back(v);
         }
        vector<int> ans;
         for(int i=0;i<n;i++)
         {
             unordered_map<int,int> vis;
             int cnt=0;
             dfs(i,cnt,vis);
             if(cnt==n)
                 ans.push_back(i);
             
         }
        if(ans.size()==1)
            return ans[0];
        else
            return -1;
    }
};