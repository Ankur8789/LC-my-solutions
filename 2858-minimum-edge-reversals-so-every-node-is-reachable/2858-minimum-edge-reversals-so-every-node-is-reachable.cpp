class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> adj;
    vector<int> up,dw;
    unordered_map<int,int> vis;
    int total=0;
    void dfs(int u,int par)
    {
        // vis[u]=1;
        for(auto x: adj[u])
        {
            int v=x.first;
            int wt=x.second;
            if(v==par)
                continue;
            if(wt==1)
                total++;
            // u->v down edge
            if(wt==0)
                dw[v]=dw[u]+1;
            else
                dw[v]=dw[u];
            // u<-v
            if(wt==1)
                up[v]=up[u]+1;
            else
                up[v]=up[u];
            dfs(v,u);
                
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) 
    {
         up.resize(n);
         dw.resize(n);
         // forward and reverse edges
         for(auto t: edges)
         {
             int u=t[0];
             int v=t[1];
             adj[u].push_back({v,0});
             adj[v].push_back({u,1});
         }
        // first step is rooting at 1/0
        // second is dfs
        // how we calculate the answer
        // suppose it is rooted at 1 so the ans would be total up edges minus the one contained between 1 and u
        dfs(0,-1);
        vector<int> ans;
        for(int i=0;i<n;i++)
            ans.push_back(dw[i]+total-up[i]);
        return ans;
    }
};