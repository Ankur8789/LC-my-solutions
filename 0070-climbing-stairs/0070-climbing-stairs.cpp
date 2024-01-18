class Solution {
public:
    int dp[46];
    int f(int n)
    {
        if(n<0)
            return 0;
        if(n==0)
            return 1;
        auto &x = dp[n];
        if(x!=-1)
            return x;
        return x = f(n-1)+f(n-2);
    }
    int climbStairs(int n) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=f(n);
        return ans;
    }
};