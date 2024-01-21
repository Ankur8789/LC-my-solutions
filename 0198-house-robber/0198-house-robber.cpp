class Solution {
public:
    int dp[101][2];
    int f(int i,int last,vector<int>& nums)
    {
        if(i==nums.size())
            return 0;
        auto& x = dp[i][last];
        if(x!=-1)
            return x;
        int ans=0;
        if(!last)
            ans=max(ans,nums[i]+f(i+1,1,nums));
        ans=max(ans,f(i+1,0,nums));
        return x = ans;
    }
    int rob(vector<int>& nums)
    {
       memset(dp,-1,sizeof(dp));
       int ans=f(0,0,nums);
       return ans;
    }
};