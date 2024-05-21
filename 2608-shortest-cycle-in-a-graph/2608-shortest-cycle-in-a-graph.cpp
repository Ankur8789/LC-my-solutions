class Solution {
public:
    unordered_map<int,vector<int>> adj;
    int calc(int u)
    {
        unordered_map<int,int> dis;
        queue<pair<int,int>> q;
        q.push({u,-1});
        dis[u]=0;
        int ans=1e9;
        while(q.size()>0)
        {
            auto x=q.front();
            q.pop();
            int a=x.first;
            int par=x.second;
            for(auto v: adj[a])
            {
                if(v==par)continue;
                if(dis.find(v)==dis.end())
                {
                    dis[v]=dis[a]+1;
                    q.push({v,a});
                }
                else
                {
                    ans=min(ans,dis[v]+dis[a]+1);
                    break;
                }
            }
        }
        return ans;
    }
    int findShortestCycle(int n, vector<vector<int>>& edges)
    {
        int ans=1e9;
        for(auto x: edges)
        {
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++)
        {
            ans=min(ans,calc(i));
        }
        if(ans==1e9)ans=-1;
        return ans;
    }
};