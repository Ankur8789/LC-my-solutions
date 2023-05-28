class Solution {
public:
    int f(int i,int j,vector<int>& v,vector<vector<int>>& dp)
    {
        if(i+1==j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=INT_MAX;
        for(int idx=i+1;idx<j;idx++)
        {
            ans=min(ans,v[j]-v[i]+f(i,idx,v,dp)+f(idx,j,v,dp));
        }
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) 
    {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        vector<vector<int>> dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        sort(cuts.begin(),cuts.end());
        int ans=f(0,cuts.size()-1,cuts,dp);
        return ans;
    }
};