class Solution {
public:
    typedef long long ll;
    const int mod=1e9+7;
    unordered_map<int,vector<pair<ll,ll>>> adj;
    vector<ll> dp;
    ll dfs(ll x,vector<ll>& dis,ll n)
    {
        if(x==n)  
           return 1;
        if(dp[x]!=-1)
            return dp[x];
        ll res=0;
        for(auto t: adj[x])
        {
            ll v=t.first;
            ll wt=t.second;
            if(dis[x]>dis[v])
            {
                res+=dfs(v,dis,n);
                res%=mod;
            }
        }
        return dp[x]=res;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) 
    {
        
        for(auto t: edges)
        {
            adj[t[0]].push_back({t[1],t[2]});
            adj[t[1]].push_back({t[0],t[2]});
        }
        multiset<pair<ll,ll>> ms;
        vector<ll> dis(n+1,1e12);
        dis[n]=0;
        ms.insert({0,n});
        while(ms.size()>0)
        {
            auto t=*ms.begin();
            ms.erase(ms.begin());
            ll d=t.first;
            ll u=t.second;
            for(auto x: adj[u])
            {
                ll v=x.first;
                ll wt=x.second;
                if(dis[v]>d+wt)
                {
                    if(ms.count({dis[v],v}))
                        ms.erase({dis[v],v});
                    dis[v]=d+wt;
                    ms.insert({dis[v],v});
                }
            }
        }
        dp.resize(n+1,-1);
        int ans=dfs(1,dis,n);
        return ans;
        
    }
};