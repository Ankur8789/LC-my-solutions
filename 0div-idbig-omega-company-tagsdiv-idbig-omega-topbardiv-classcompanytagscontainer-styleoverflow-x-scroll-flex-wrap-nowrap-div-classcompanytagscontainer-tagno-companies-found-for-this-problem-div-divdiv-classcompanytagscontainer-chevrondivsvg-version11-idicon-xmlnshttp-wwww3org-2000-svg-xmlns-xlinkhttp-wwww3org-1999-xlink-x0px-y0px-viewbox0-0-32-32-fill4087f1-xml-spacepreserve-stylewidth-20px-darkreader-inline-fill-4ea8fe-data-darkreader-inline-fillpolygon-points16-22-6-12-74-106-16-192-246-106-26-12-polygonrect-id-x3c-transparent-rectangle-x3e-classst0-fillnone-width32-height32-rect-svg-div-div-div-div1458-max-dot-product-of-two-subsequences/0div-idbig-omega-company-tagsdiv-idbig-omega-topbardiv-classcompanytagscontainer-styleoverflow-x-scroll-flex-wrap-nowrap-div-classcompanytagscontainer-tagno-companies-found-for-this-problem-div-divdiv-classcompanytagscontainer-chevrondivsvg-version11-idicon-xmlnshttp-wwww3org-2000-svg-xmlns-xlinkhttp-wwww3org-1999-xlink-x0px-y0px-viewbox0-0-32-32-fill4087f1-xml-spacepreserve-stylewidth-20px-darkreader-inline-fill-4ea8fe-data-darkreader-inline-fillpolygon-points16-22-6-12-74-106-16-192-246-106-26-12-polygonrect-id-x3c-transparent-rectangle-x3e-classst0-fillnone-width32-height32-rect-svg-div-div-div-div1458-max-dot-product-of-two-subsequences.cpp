class Solution {
public:
    int dp[501][501][2];
    int f(int i,int j,vector<int>& nums1,vector<int>& nums2,int take)
    {
      if(i==nums1.size())
      {
          if(take)
              return 0;
          else
              return -1e9;
      }
      if(j==nums2.size())
      {
          if(take)
              return 0;
          else
              return -1e9;
      }
        if(dp[i][j][take]!=-1)
            return dp[i][j][take];
      int a=nums1[i]*nums2[j]+f(i+1,j+1,nums1,nums2,take|1);
      int b=max(f(i+1,j,nums1,nums2,take),f(i,j+1,nums1,nums2,take));
        return dp[i][j][take]=max(a,b);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2)
    {  memset(dp,-1,sizeof(dp));
       auto ans=f(0,0,nums1,nums2,0);
        return ans;
    }
};