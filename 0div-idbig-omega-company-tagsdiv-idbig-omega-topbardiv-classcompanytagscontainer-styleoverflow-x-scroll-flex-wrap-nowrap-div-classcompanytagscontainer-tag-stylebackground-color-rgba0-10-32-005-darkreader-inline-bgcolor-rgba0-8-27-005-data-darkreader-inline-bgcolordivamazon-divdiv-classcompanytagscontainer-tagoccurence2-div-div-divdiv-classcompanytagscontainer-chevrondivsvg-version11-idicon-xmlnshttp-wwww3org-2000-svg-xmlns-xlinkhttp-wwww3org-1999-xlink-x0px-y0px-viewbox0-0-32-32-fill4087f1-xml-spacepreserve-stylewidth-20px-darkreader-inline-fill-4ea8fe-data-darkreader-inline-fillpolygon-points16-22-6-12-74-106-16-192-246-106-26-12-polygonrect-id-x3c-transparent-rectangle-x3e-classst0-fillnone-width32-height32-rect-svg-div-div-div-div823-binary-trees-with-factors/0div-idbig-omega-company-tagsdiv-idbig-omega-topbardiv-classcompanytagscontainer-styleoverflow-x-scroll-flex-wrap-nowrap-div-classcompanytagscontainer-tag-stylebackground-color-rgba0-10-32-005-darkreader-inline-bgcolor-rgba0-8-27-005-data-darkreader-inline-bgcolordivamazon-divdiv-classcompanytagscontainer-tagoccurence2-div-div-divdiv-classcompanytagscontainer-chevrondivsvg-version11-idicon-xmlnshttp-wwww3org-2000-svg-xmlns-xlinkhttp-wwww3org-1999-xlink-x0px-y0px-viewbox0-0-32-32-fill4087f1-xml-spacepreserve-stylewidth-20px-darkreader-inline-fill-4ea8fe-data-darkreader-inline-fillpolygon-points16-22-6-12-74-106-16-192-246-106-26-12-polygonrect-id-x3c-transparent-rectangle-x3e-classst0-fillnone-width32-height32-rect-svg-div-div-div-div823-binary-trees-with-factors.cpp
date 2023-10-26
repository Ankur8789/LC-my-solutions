class Solution {
public:
    typedef long long ll;
    const ll mod=1e9+7;
    unordered_map<ll,ll> mp;
    ll dp[1001];
    ll f(ll i,vector<int>& arr)
    {
        if(dp[i]!=-1)
            return dp[i];
            
        ll ans=1;
        for(ll j=0;j<i;j++)
        {
            if((arr[i]%arr[j])==0 && mp.find(arr[i]/arr[j])!=mp.end())
            {
                // do possible subtrees
                ll a=j;
                ll b=mp[arr[i]/arr[j]];
                ll res=1;
                // left possible subtrees se ek chune
                res*=f(a,arr);
                res%=mod;
                // right possible se ek chune
                res*=f(b,arr);
                res%=mod;
                // ans=(left C 1)*(right C 1)
                ans+=res;
                ans%=mod;
            }
        }
        return dp[i]=ans;
    }
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        sort(begin(arr),end(arr));
        for(ll i=0;i<arr.size();i++)
            mp[arr[i]]=i;
        memset(dp,-1,sizeof(dp));
        ll ans=0;
        for(ll i=0;i<arr.size();i++)
        {
           ans+=f(i,arr);
           ans%=mod;
        }
        return (int)ans;
    }
};