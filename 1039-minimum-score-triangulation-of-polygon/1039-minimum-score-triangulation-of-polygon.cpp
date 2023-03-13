class Solution {
public:
    int dp[51][51];
    int f(int i,int j,vector<int>&v)
    {
        if(j==i+1)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=INT_MAX;
        for(int idx=i+1;idx<j;idx++)
        {
            ans=min(ans,v[i]*v[j]*v[idx]+f(i,idx,v)+f(idx,j,v));
        }
        return dp[i][j]=ans;
    }
    int minScoreTriangulation(vector<int>& v)
    {   
        int n=v.size();
        memset(dp,-1,sizeof(dp));
         int ans=f(0,n-1,v);
        return ans;
    }
};