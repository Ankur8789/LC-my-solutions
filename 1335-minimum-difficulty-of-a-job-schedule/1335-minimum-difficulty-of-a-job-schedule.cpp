typedef long long ll;
#define INF 2e18
class Solution {
public:
    ll dp[301][11];
    ll f(ll i,ll d,vector<int>& jd)
    {
        if(i==jd.size() && d==0)
            return 0;
        if(i==jd.size() || d==0)
            return INF;
        auto &x=dp[i][d];
        if(x!=-1)
            return x;
        ll ans=INF;
        ll maxi=-1e18;
        for(ll idx=i;idx<jd.size();idx++)
        {
            maxi=max(maxi,1LL*jd[idx]);
            ans=min(ans,maxi+f(idx+1,d-1,jd));
        }
        return x=ans;
    }
    int minDifficulty(vector<int>& jd, int d) 
    {
        memset(dp,-1,sizeof(dp));
        ll ans=f(0,d,jd);
        ans=(ans==INF)?-1:ans;
        return (int)ans;
    }
};