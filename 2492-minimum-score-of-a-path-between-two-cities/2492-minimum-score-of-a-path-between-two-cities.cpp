class Solution {
public:
    vector<int> adj[100001];
    int vis[100001];
    void dfs(int x)
    {
        vis[x]=1;
        for(int i=0;i<adj[x].size();i++)
        {
            if(vis[adj[x][i]]==0)
                dfs(adj[x][i]);
        }
    }
    int minScore(int n, vector<vector<int>>& edges) 
    {
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(1);
        int mn=INT_MAX;
        for(int i=0;i<edges.size();i++)
        {
            if(vis[edges[i][0]]==1)
                mn=min(mn,edges[i][2]);
        }
        return mn;
    }
};