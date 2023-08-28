// binary lifting
class TreeAncestor {
public:
    int dp[50001][20];
    int log=0;
    int depth[50001];
    unordered_map<int,vector<int>> adj;
    void dfs(int x,int dis)
    {
        depth[x]=dis;
        for(auto t: adj[x])
        {
            depth[t]=dis+1;
            dfs(t,dis+1);
        }
        
    }
    TreeAncestor(int n, vector<int>& parent) 
    {
        for(int i=0;i<n;i++)
        {
           if(i!=0)
               adj[parent[i]].push_back(i);
        }
        while((1<<(log))<=n)
            log++;
        parent[0]=0;
        depth[0]=0;
        dfs(0,0);
        for(int v=0;v<n;v++)
        {
            dp[v][0]=parent[v];
            
        }
        for(int j=1;j<log;j++)
        {
            for(int v=0;v<n;v++)
            {
                
                dp[v][j]=dp[dp[v][j-1]][j-1];
            }
        }
        for(int i=0;i<n;i++)cout<<depth[i]<<" ";
    }
    
    int getKthAncestor(int node, int k)
    {
        if(depth[node]<k)
            return -1;
        for(int i=0;i<log;i++)
        {
            if((k>>i)&1)
                node=dp[node][i];
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */