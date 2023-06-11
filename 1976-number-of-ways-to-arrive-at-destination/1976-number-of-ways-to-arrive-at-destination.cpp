class Solution {
public:
    const int mod=1e9+7;
    typedef long  long ll;
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        unordered_map<ll,vector<pair<ll,ll>>> adj;
        for(auto t: roads)
        {
            adj[t[0]].push_back({t[1],t[2]});
            adj[t[1]].push_back({t[0],t[2]});
        }
        vector<ll> dis(n,1e18);
        vector<ll> cnt(n);
        set<pair<ll,ll>> q;
        q.insert({0,0});
        dis[0]=0;
        cnt[0]=1;
        while(q.size()>0)
        {
            auto p=*q.begin();
            q.erase(q.begin());
            ll len=p.first;
            ll u=p.second;
            for(auto t: adj[u])
            {
                if(dis[t.first]>len+t.second)
                {
                    dis[t.first]=len+t.second;
                    cnt[t.first]=cnt[u];
                    q.insert({dis[t.first],t.first});
                }
                else if(dis[t.first]==len+t.second)
                {
                    cnt[t.first]+=cnt[u];
                    cnt[t.first]%=mod;
                }
            }
        }
        for(auto t: cnt)
            cout<<t<<" ";
        cout<<endl;
        // for(auto t: dis)
        //     cout<<t<<" ";
        // cout<<endl;
        return cnt[n-1];
    }
};