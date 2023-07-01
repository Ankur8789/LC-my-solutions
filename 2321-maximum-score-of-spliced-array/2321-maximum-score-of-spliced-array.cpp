class Solution {
public:
    int dp[100001][3][3];
    int f(int i,int t,vector<int>& nums1, vector<int>& nums2,int taken,int init)
    {
        if(i==nums1.size())
            return 0;
        if(dp[i][taken][init]!=-1)
            return dp[i][taken][init];
        int ans=-1e9;
        if(i==0)
        {
           //arr1
           ans=max(ans,nums1[i]+f(i+1,0,nums1,nums2,0,0));
           ans=max(ans,nums1[i]+f(i+1,0,nums1,nums2,1,0));
           ans=max(ans,nums2[i]+f(i+1,0,nums1,nums2,1,0));
           //arr2
           ans=max(ans,nums2[i]+f(i+1,0,nums1,nums2,0,1));
           ans=max(ans,nums2[i]+f(i+1,0,nums1,nums2,1,1));
           ans=max(ans,nums1[i]+f(i+1,0,nums1,nums2,1,1));
        }
        else
        {
           if(init==0)
           {
              if(taken==2)
              {
                  ans=max(ans,nums1[i]+f(i+1,t,nums1,nums2,taken,init));
              }
              else if(taken==1)
              {
                  ans=max(ans,nums2[i]+f(i+1,t,nums1,nums2,taken,init));
                  ans=max(ans,nums2[i]+f(i+1,t,nums1,nums2,2,init));
              }
              else
              {
                  ans=max(ans,nums1[i]+f(i+1,t,nums1,nums2,taken,init));
                  ans=max(ans,nums1[i]+f(i+1,t,nums1,nums2,1,init));
              }
           }
           else
           {
              if(taken==2)
              {
                  ans=max(ans,nums2[i]+f(i+1,t,nums1,nums2,taken,init));
              }
              else if(taken==1)
              {
                  ans=max(ans,nums1[i]+f(i+1,t,nums1,nums2,taken,init));
                  ans=max(ans,nums1[i]+f(i+1,t,nums1,nums2,2,init));
              }
              else
              {
                  ans=max(ans,nums2[i]+f(i+1,t,nums1,nums2,taken,init));
                  ans=max(ans,nums2[i]+f(i+1,t,nums1,nums2,1,init));
              }
           }
              
        }
        return dp[i][taken][init]=ans;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) 
    {
       memset(dp,-1,sizeof(dp));
       int ans=f(0,0,nums1,nums2,0,0);
       return ans;
    }
};