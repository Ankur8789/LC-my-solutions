class Solution {
public:
    int dp[51][51];
    int f(int i,int j,vector<int>& val)
    {
        if(i==j-1)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=INT_MAX;
        for(int idx=i+1;idx<j;idx++)
        {
            ans=min(ans,val[i]*val[j]*val[idx]+f(i,idx,val)+f(idx,j,val));
        }
        return dp[i][j]=ans;

    }
    int minScoreTriangulation(vector<int>& values)
    {
        memset(dp,-1,sizeof(dp));
        int ans=f(0,values.size()-1,values);
        return ans;
    }
};