class Solution {
public:
    int dp[21][10001];
    int f(int i,int sum,vector<int>& roads)
    {
        if(i==roads.size())
        {
            if(sum==0)
                return 0;
            else
                return -1e5;
        }
        if(dp[i][sum+5000]!=-1)
            return dp[i][sum+5000];
        int ans=-1e9;
        ans=max(ans,roads[i]+f(i+1,sum+roads[i],roads));
        ans=max(ans,roads[i]+f(i+1,sum-roads[i],roads));
        ans=max(ans,f(i+1,sum,roads));
        return dp[i][sum+5000]=ans;
    }
    int tallestBillboard(vector<int>& rods) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=f(0,0,rods);
        return ans/2;
    }
};