class Solution {
public:
    const int mod=1e9+7;
    int dp[31][1001];
    int f(int i,int k,int tg,int n)
    {
        if(i==n && tg==0)
            return 1;
        if(i==n || tg==0)
            return 0;
        if(tg<0)
            return 0;
        auto& x=dp[i][tg];
        if(x!=-1)
            return x;
        int ans=0;
        for(int idx=1;idx<=k;idx++)
            ans+=f(i+1,k,tg-idx,n),ans%=mod;
        return x=ans;
    }
    int numRollsToTarget(int n, int k, int target) 
    {
       memset(dp,-1,sizeof(dp));
       int ans=f(0,k,target,n);
       return ans;
    }
};