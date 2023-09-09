class Solution {
public:
    int dp[201][1001];
    int f(int i,int t,vector<int>& nums)
    {
        if(t==0)
            return 1;
        if(i==nums.size())
            return 0;
        if(dp[i][t]!=-1)
            return dp[i][t];
        if(nums[i]<=t)
            return dp[i][t]=f(0,t-nums[i],nums)+f(i+1,t,nums);
        else
            return dp[i][t]=f(i+1,t,nums);
    }
    int combinationSum4(vector<int>& nums, int target) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=f(0,target,nums);
        return ans;
    }
};