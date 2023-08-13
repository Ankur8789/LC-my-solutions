class Solution {
public:
    int dp[100001];
    bool f(int i,vector<int>& nums)
    {
        if(i>=nums.size())
            return true;
        if(dp[i]!=-1)
            return dp[i];
        bool ans=false;
        // 2 wala
        if(i+1<nums.size() && nums[i+1]==nums[i])
            ans|=f(i+2,nums);
        // 3 equal
        if(i+1<nums.size() && i+2<nums.size() && nums[i]==nums[i+1] && nums[i]==nums[i+2])
            ans|=f(i+3,nums);
        // 3 cons
        if(i+1<nums.size() && i+2<nums.size() && nums[i]+1==nums[i+1] && nums[i+1]+1==nums[i+2])
            ans|=f(i+3,nums);
        return dp[i]=ans;
        
    }
    bool validPartition(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp));
        bool ans=f(0,nums);
        return ans;
    }
};