class Solution {
public:
    int dp[8][(1<<14)];
    int f(int idx,int msk,vector<int>& nums)
    {
       if(msk==powl(2,nums.size())-1)
           return 0;
        if(dp[idx][msk]!=-1)
            return dp[idx][msk];
       int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(i==j)
                    continue;
                if(((msk>>i)&1)==0 && ((msk>>j)&1)==0)
                {
                    int tmpmsk=msk;
                    tmpmsk|=(1<<i);
                    tmpmsk|=(1<<j);
                    ans=max(ans,idx*__gcd(nums[i],nums[j])+f(idx+1,tmpmsk,nums));
                }
            }
        }
        return dp[idx][msk]=ans;
    }
    int maxScore(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=f(1,0,nums);
        return ans;
    }
};