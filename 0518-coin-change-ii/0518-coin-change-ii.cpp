class Solution {
public:
    int dp[301][5001];
    int f(int i,int amount,vector<int>& coins)
    {
        if(amount<0)
            return 0;
        if(amount==0)
            return 1;
        if(i==coins.size())
            return 0;
        if(dp[i][amount]!=-1)
            return dp[i][amount];
        int ans=0;
        ans+=f(i,amount-coins[i],coins);
        ans+=f(i+1,amount,coins);
        return dp[i][amount]=ans;
    }
    int change(int amount, vector<int>& coins) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=f(0,amount,coins);
        return ans;
    }
};