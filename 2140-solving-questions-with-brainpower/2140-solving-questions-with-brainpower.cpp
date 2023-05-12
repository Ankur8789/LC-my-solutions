class Solution {
public:
    typedef long long ll;
    ll dp[100001];
    ll f(ll i,vector<vector<int>>& qq)
    {
        if(i>=qq.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
       ll ans=0;
       ans=max(ans,f(i+1,qq));
       ans=max(ans,qq[i][0]+f(i+qq[i][1]+1,qq));
       return dp[i]=ans;
        
    }
    long long mostPoints(vector<vector<int>>& qq) 
    {
        memset(dp,-1,sizeof(dp));
        ll ans=f(0,qq);
        return ans;
    }
};