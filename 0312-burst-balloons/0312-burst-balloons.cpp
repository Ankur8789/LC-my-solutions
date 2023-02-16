class Solution {
public:
    int dp[301][301];
    int f(int i,int j,vector<int>& nums)
    {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=INT_MIN;
        for(int idx=i;idx<=j;idx++)
        {
            ans=max(ans,nums[idx]*nums[i-1]*nums[j+1]+f(i,idx-1,nums)+f(idx+1,j,nums));
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums)
    {   memset(dp,-1,sizeof(dp));
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int ans=f(1,n,nums);
        return ans;
    }
};