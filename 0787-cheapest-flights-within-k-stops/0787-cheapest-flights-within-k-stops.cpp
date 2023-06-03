class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> adj;
    //piche se aake koi value kko change na krr de
    int findCheapestPrice(int n, vector<vector<int>>& fli, int src, int dst, int k)
    {
        for(auto t:fli)
        {
            adj[t[0]].push_back({t[1],t[2]});
        }
        vector<int> dis(n,1e9);
        dis[src]=0;
        queue<vector<int>> q;
        q.push({0,src,0});
        while(q.size()>0)
        {
            auto x=q.front();
            q.pop();
            if(x[0]>k)
                continue;
            for(auto t: adj[x[1]])
            {
                int u=x[1];
                int v=t.first;
                int wt=t.second;
                int lc=x[2];
                int st=x[0];
                if(dis[v]>lc+wt && st<=k)
                {
                    if(st==k && v!=dst)
                        continue;
                    dis[v]=lc+wt;
                    q.push({st+1,v,dis[v]});
                }
            }
        }
        for(auto t: dis)cout<<t<<" ";
        if(dis[dst]==1e9)
            return -1;
        return dis[dst];
        
    }
};