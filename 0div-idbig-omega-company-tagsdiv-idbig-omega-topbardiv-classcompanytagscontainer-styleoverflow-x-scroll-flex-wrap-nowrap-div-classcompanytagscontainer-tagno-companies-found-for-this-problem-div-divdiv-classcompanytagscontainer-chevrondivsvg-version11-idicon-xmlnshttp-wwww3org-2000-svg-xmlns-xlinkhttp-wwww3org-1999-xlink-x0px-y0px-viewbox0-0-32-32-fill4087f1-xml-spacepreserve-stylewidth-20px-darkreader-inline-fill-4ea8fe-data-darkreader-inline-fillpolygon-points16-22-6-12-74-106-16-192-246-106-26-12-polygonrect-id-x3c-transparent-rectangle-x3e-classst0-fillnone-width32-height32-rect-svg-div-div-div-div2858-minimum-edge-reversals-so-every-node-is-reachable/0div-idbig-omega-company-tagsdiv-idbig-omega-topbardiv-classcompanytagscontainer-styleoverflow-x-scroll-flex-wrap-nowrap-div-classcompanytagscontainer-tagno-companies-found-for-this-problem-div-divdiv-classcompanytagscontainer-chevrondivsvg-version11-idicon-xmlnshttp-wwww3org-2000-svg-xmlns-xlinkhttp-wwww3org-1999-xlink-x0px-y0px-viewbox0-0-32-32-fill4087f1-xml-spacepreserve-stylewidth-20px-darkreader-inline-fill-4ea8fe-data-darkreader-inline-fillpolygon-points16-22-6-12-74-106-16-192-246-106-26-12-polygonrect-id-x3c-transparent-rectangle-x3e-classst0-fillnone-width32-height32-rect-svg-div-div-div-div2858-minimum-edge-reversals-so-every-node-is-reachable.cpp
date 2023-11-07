class Solution {
public:
    vector<int> up,dw;
    unordered_map<int,vector<pair<int,int>>> adj;
    int total;
    void dfs(int u,int par)
    {
        for(auto x: adj[u])
        {
            int v=x.first;
            int wt=x.second;
            if(v==par)
                continue;
            // wt=0 u->v
            if(wt==0)
                dw[v]=dw[u]+1;
            else
                dw[v]=dw[u];
            if(wt==1)
                up[v]=up[u]+1;
            else
                up[v]=up[u];
            dfs(v,u);
            if(wt==1)
                total++;
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) 
    {
        up.resize(n);
        dw.resize(n);
        for(auto t: edges)
        {
            int u=t[0];
            int v=t[1];
            adj[u].push_back({v,0});
            adj[v].push_back({u,1});
        }
        total=0;
        dfs(0,-1);
        vector<int> ans;
        for(int i=0;i<n;i++)
            ans.push_back(dw[i]+total-up[i]);
        return ans;
        
    }
};