class Solution {
public:
    typedef long long ll;
    const int mod=1e9+7;
    ll dp[101][101];
    ll f(int goal,int n,int k)
    {
        if(n==0 && goal==0)
            return 1;
        if(n==0)
            return 0;
        if(goal==0)
            return 0;
        if(dp[goal][n]!=-1)
            return dp[goal][n];
        ll ans=0;
        ans+=f(goal-1,n-1,k)*n;
        ans%=mod;
        ans+=f(goal-1,n,k)*max(n-k,0);
        ans%=mod;
        return dp[goal][n]=ans;
    }
    int numMusicPlaylists(int n, int goal, int k) 
    {
       memset(dp,-1,sizeof(dp));
       int ans=f(goal,n,k);
       return ans;
    }
};