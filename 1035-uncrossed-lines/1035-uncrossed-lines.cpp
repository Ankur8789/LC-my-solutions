class Solution {
public:
    int dp[501][501];
    int f(int i,int j,vector<int>& nums1, vector<int>& nums2)
    {
        if(i==nums1.size() || j==nums2.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(nums1[i]==nums2[j])
        {
           int a=f(i+1,j,nums1,nums2);
           int b=f(i,j+1,nums1,nums2);
           int c=1+f(i+1,j+1,nums1,nums2);
            return dp[i][j]=max({a,b,c});
        }
        else
        {
           int a=f(i+1,j,nums1,nums2);
           int b=f(i,j+1,nums1,nums2);
           int c=f(i+1,j+1,nums1,nums2);
           return dp[i][j]=max({a,b,c});
        }
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=f(0,0,nums1,nums2);
        return ans;
    }
};