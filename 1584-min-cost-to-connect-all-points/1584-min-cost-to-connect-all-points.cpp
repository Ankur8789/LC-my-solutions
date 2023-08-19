class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        vector<vector<int>> edges;
        int k=0;
        map<pair<int,int>,int> mp;
        int n=points.size();
        // for(int i=0;i<n;i++)
        //     mp[{points[i][0],points[i][1]}]=i+1;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int u=i+1;
                int v=j+1;
                int wt=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({u,v,wt});
            }
        }
        // wt node parent
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto t: edges)
        {
            int u=t[0];
            int v=t[1];
            int wt=t[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        multiset<pair<int,int>> ms;
        int sum=0;
        ms.insert({0,1});
        vector<int> vis(n+2);
        while(ms.size()>0)
        {
            auto x=*ms.begin();
            ms.erase(ms.begin());
            int  wt=x.first;
            int u=x.second;
            // int par=x[2];
            if(vis[u]==1)
                continue;
            else
            {
                sum+=wt;
                vis[u]=1;
                for(auto t: adj[u])
                {
                    int v=t.first;
                    int w=t.second;
                    if(vis[v]==0)
                    {
                        ms.insert({w,v});
                    }
                }
            }
        }
        return sum;
        
    }
};