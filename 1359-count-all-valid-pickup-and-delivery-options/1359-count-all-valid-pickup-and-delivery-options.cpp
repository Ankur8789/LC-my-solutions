class Solution {
public:
    const int mod=1e9+7;
    typedef long long ll;
    ll dp[501][501];
    ll f(ll pc,ll del,ll n)
    {
        if(pc<0 || del<0 || del<pc)
            return 0;
        if(pc==0 && del==0)
            return 1;
        if(dp[pc][del]!=-1)
            return dp[pc][del];
        ll ans=0;
        ans+=(pc*f(pc-1,del,n))%mod;
        ans%=mod;
        ans+=((del-pc)*f(pc,del-1,n))%mod;
        ans%=mod;
         // cout<<i<<" "<<curr<<" "<<ans<<endl;
        return dp[pc][del]=ans;
    }
    int countOrders(int n) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=f(n,n,n);
        return ans;
    }
};