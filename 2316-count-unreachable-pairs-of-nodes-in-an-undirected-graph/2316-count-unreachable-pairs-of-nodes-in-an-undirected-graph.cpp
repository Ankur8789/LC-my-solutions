class Solution {
public:
    typedef long long ll;
    vector<ll> adj[100001];
    ll vis[100001];
    ll ps;
    void dfs(ll x)
    {
        vis[x]=1;
        ps++;
        for(auto t:adj[x])
        {
            if(vis[t]==0)
                dfs(t);
        }
    }
    long long countPairs(int n, vector<vector<int>>& e) 
    {
        for(auto t: e)
        {
            adj[t[0]].push_back(t[1]);
            adj[t[1]].push_back(t[0]);           
        }
        ll cc=0;
        vector<ll> cnt;
        ps=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                dfs(i);
                cc++;
                cnt.push_back(ps);
                ps=0;
            }
        }
        if(cc==1)
            return 0;
            
        ll ans=0;
        ll suff=0;
        for(auto t: cnt)
            suff+=t;
        for(auto t: cnt)
        {
            suff-=t;
            ans+=t*(suff);
        }
        return ans;
    }
};