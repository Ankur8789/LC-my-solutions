class Solution {
public:
    int dp[21][21][2];
    int f(int i,int j,vector<int>& nums,int turn)
    {
        if(i>j)
            return 0;
        if(dp[i][j][turn]!=-1)
            return dp[i][j][turn];
        if(turn)
            return dp[i][j][turn]=max(nums[i]+f(i+1,j,nums,turn^1),nums[j]+f(i,j-1,nums,turn^1));
        else
            return dp[i][j][turn]=min(f(i+1,j,nums,turn^1),f(i,j-1,nums,turn^1));
    }
    bool PredictTheWinner(vector<int>& nums) 
    {
       int tot=0;
       for(auto t: nums)
           tot+=t;
        memset(dp,-1,sizeof(dp));
       int res=f(0,nums.size()-1,nums,1);
       if(tot-res<=res)
           return 1;
        else
           return 0;
    }
};