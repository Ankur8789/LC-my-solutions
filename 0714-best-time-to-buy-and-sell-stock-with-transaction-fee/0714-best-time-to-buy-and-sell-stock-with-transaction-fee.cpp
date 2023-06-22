class Solution {
public:
    int dp[50001][2];
    int f(int i,int t,vector<int>& prices, int fee)
    {
        if(i==prices.size())
            return 0;
        if(dp[i][t]!=-1)
            return dp[i][t];
        if(t)
        return dp[i][t]=max(-prices[i]+f(i+1,t^1,prices,fee),f(i+1,t,prices,fee));
        else
        return dp[i][t]=max(prices[i]-fee+f(i+1,t^1,prices,fee),f(i+1,t,prices,fee));
        
    }
    int maxProfit(vector<int>& prices, int fee) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=f(0,1,prices,fee);
        return ans;
    }
};