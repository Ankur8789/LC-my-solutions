class Solution {
public:
    vector<int> adj[100001];
    int vis[100001];
    void dfs(int x)
    {
        vis[x]=1;
        for(auto t: adj[x])
        {
            if(vis[t]==0)
                dfs(t);
        }
    }
    int makeConnected(int n, vector<vector<int>>& cc) 
    {
        for(auto t: cc)
        {
            adj[t[0]].push_back(t[1]);
            adj[t[1]].push_back(t[0]);
        }
        int op=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                dfs(i);
                ++op;
            }
        }
        
        if(cc.size()>=n-1)
            return op-1;
        else
            return -1;
        
    }
};