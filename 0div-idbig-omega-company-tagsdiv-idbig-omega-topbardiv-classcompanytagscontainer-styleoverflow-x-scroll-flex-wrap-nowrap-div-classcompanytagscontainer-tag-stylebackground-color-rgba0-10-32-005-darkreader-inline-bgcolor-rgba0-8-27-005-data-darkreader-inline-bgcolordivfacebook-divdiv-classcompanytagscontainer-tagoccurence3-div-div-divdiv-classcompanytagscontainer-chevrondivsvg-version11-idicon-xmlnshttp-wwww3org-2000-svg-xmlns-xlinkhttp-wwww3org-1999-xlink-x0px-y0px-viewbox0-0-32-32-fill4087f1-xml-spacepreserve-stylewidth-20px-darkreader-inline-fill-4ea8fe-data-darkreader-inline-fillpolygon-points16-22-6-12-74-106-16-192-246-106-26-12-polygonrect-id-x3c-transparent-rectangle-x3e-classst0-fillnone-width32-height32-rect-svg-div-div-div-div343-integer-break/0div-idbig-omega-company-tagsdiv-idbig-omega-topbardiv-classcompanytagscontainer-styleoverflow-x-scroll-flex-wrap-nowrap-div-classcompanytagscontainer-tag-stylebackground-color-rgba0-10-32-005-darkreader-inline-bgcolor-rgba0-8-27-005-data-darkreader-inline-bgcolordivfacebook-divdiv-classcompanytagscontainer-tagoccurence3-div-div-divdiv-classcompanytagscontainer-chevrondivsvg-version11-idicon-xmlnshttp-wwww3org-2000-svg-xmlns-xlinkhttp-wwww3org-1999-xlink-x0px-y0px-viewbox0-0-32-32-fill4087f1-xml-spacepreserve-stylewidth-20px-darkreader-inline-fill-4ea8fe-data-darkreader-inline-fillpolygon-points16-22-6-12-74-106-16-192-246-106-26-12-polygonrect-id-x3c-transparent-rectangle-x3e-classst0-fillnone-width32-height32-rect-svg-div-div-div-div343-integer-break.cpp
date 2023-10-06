class Solution {
public:
    int dp[61][61];
    int f(int n,int cc)
    {
        if(n==0 )
        {
            if(cc>=2)
                return 1;
            else
                return 0;
        }
        if(dp[n][cc]!=-1)
            return dp[n][cc];
       int ans=-1e5;
       for(int i=1;i<=n;i++)
       {
           ans=max(ans,i*f(n-i,cc+1));
       }
        return dp[n][cc]=ans;
    }
    int integerBreak(int n) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=f(n,0);
        return ans;
    }
};