class Solution {
public:
    int dp[5001][5];
    int f(int i,int st,vector<int>& nums)
    {
        if(i==nums.size())
          return 0;
        if(dp[i][st]!=-1)
            return dp[i][st];
        int ans=0;
        if(st==0)
        {
            ans+=f(i+1,1,nums);
            ans+=f(i+1,st,nums);
        }
        else if(st==1)
        {
            ans+=f(i+1,st+1,nums);
        }
        else if(st==2)
        {
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
                ans+=1+f(i+1,st+1,nums);
        }
        else if(st==3)
        {
           if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
                ans+=1+f(i+1,st+1,nums);   
        }
        else
        {
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
                ans+=1+f(i+1,min(4,st+1),nums);   
        }
        return dp[i][st]=ans;
    }
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=f(0,0,nums);
        return ans;
    }
};