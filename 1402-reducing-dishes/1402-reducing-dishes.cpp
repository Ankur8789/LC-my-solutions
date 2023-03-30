class Solution {
public:
    int dp[501][501];
    int f(int i,vector<int>& ss,int t)
    {
        if(i==ss.size())
            return 0;
        if(dp[i][t]!=-1)
            return dp[i][t];
        return dp[i][t]=max(t*ss[i]+f(i+1,ss,t+1),f(i+1,ss,t));
    }
    
    int maxSatisfaction(vector<int>& ss)
    {
        sort(ss.begin(),ss.end());
        memset(dp,-1,sizeof(dp));
        int ans=f(0,ss,1);
        return ans;
    }
};