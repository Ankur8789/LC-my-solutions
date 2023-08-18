class Solution {
public:
    unordered_map<int,set<int>> adj;
    map<pair<int,int>,int> pres;
    int max(int a,int b)
    {
        if(a>b)
            return a;
        else
            return b;
    }
    int maximalNetworkRank(int n, vector<vector<int>>& roads) 
    {
        for(auto t: roads)
        {
            int u=t[0];
            int v=t[1];
            if(pres.find({u,v})!=pres.end() || pres.find({v,u})!=pres.end())
                continue;
            adj[u].insert(v);
            adj[v].insert(u);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(adj[i].find(j)!=adj[i].end())
                {
                    ans=max(ans,adj[i].size()+adj[j].size()-1);
                }
                else
                {
                    ans=max(ans,adj[i].size()+adj[j].size());
                }
            }
        }
        return ans;
        
    }
};