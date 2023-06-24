class Solution {
public:
    typedef long long ll;
    unordered_map<ll,vector<ll>> adj;
    ll f(ll v,vector<ll>& cnt)
    {
        if(adj[v].size()==0)
        {
            cnt[v]=1;
            return cnt[v];
        }
        ll ans=0;
        for(auto t: adj[v])
        {
            ans+=f(t,cnt);
        }
        ans++;
        cnt[v]+=ans;
        return ans;
    }
    int countHighestScoreNodes(vector<int>& par) 
    {
        vector<ll> cnt(par.size());
        map<ll,ll> mp;
        for(ll i=0;i<par.size();i++)
        {
            if(par[i]==-1)
                continue;
            adj[par[i]].push_back(i);
        }
        f(0,cnt);
        ll ans=0;
        for(ll i=0;i<par.size();i++)
        {
            ll cc=1;
            for(auto t: adj[i])
                cc*=cnt[t];
            if(par[i]!=-1)
            {
                cc*=cnt[0]-cnt[i];
            }
           ans=max(ans,cc);
            mp[cc]++;
        }
       
        return mp[ans];
    }
};