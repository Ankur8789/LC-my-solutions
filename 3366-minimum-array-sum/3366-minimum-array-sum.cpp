class Solution {
public:
    int dp[101][101][101];
    int f(int i,int op1,int op2,int k,vector<int>& nums){
        if(op1<0 || op2<0)
            return 1e9;
        if(i==nums.size())
            return 0;
        auto& x=dp[i][op1][op2];
        if(x!=-1)
            return x;
        int ans=1e9;
        ans=min(ans,nums[i]+f(i+1,op1,op2,k,nums));
        // first divide 
        int val = nums[i]+1;
        val/=2;
        ans=min(ans,val+f(i+1,op1-1,op2,k,nums));
        if(val>=k){
            ans=min(ans,val-k+f(i+1,op1-1,op2-1,k,nums));
        }
        // first sub
        val=nums[i];
        if(val>=k){
            val-=k;
            ans=min(ans,val+f(i+1,op1,op2-1,k,nums));
            val++;
            val/=2;
            ans=min(ans,val+f(i+1,op1-1,op2-1,k,nums));
        }
        return x=ans;
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
       memset(dp,-1,sizeof(dp));
       int ans=f(0,op1,op2,k,nums);
       return ans;
    }
};