class Solution {
public:
    unordered_map<int,vector<int>> adj;
    int col[101];
    int vis[101];
    bool dfs(int x,int c)
    {
       vis[x]=1;
        col[x]=c;
        for(auto t: adj[x])
        {
            if(vis[t]==0)
            {
                bool h=dfs(t,c^1);
                if(!h)
                    return false;
            }
            else if(col[x]==col[t])
             return false;
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