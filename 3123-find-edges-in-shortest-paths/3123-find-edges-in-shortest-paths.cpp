class Solution {
public:
    typedef long long ll;
    unordered_map<ll,vector<pair<ll,ll>>> adj;
    vector<ll> djk(ll src , int n)
    {
        vector<ll> dis(n,1e12);
        multiset<pair<ll,ll>> ms;
        dis[src]=0;
        ms.insert({0,src});
        while(ms.size())
        {
           auto x = *ms.begin();
           ms.erase( ms.begin());
           ll d = x.first;
           ll u = x.second;
           for(auto t: adj[u])
           {
               ll v = t.first;
               ll wt = t.second;
               if(dis[v] > d + wt)
               {
                   if(ms.count({dis[v],v}))
                       ms.erase({dis[v],v});
                   dis[v] = d + wt;
                   ms.insert({dis[v],v});
               }
           }
        }
        return dis;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) 
    {
       for(auto x : edges)
       {
          ll u = x[0];
          ll v = x[1];
          ll wt = x[2];
          adj[u].push_back({v, wt});
          adj[v].push_back({u, wt});
       }
       vector<ll> dis1 = djk(0,n);
       vector<ll> dis2 = djk(n-1,n);
       vector<bool> ans;
       for(auto x: edges)
       {
           ll u = x[0];
           ll v = x[1];
           ll wt = x[2];
           if(dis1[u] + wt + dis2[v] == dis1[n-1])
           {
               ans.push_back(1);
               continue;
           }
           if(dis1[v] + wt + dis2[u] == dis1[n-1])
           {
              ans.push_back(1);
              continue;
           }
           ans.push_back(0);       
       }
       return ans;
       
    }
};