class Solution {
public:
    int dp[305][305];
    int f(int i,int j,vector<int>& nums)
    {
       if(i>j || (i+1==j))
           return 0;
       if(dp[i][j]!=-1)
           return dp[i][j];
       int ans=0;
       for(int idx=i+1;idx<j;idx++)
       {
           ans=max(ans,nums[i]*nums[idx]*nums[j]+f(i,idx,nums)+f(idx,j,nums));
       }
        return dp[i][j]=ans;
    }    
    int maxCoins(vector<int>& nums) 
    {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        memset(dp,-1,sizeof(dp));
        int ans=f(0,nums.size()-1,nums);
        return ans;
    }
};