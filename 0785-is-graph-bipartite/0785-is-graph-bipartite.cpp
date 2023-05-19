class Solution {
public:
    unordered_map<int,vector<int>> adj;
    int col[101];
    int vis[101];
    bool dfs(int v,int c)
    {
       vis[v]=1;
        col[v]=c;
        for(int i=0;i<adj[v].size();i++)
        {
            if(vis[adj[v][i]]==0)
            {
               if(dfs(adj[v][i],c^1)==false)
                   return false;
            }
            else
            {
                if(col[adj[v][i]]==c)
                    return false;
            }
                
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& g) 
    {
        for(int i=0;i<g.size();i++)
        {
            for(int j=0;j<g[i].size();j++)
                adj[i].push_back(g[i][j]);
        }
        // memset(col,-1,sizeof(col));
        for(int i=0;i<g.size();i++)
        {
            if(vis[i]==0)
            {
                if(dfs(i,0)==false)
                    return false;
            }
        }
        return true;
    }
};