class Solution {
public:
    const int mod=1e9+7;
    int f(int i,int j,vector<vector<int>>& grid,int k,int rem,vector<vector<vector<int>>>& dp)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return 0;
        if(i==grid.size()-1 && j==grid[0].size()-1)
        {
            int sum=(rem+grid[i][j])%k;
            if(sum==0)
                return 1;
            else
                return 0;
        }
        if(dp[i][j][rem]!=-1)
            return dp[i][j][rem];
        int ans=0;
        ans+=f(i+1,j,grid,k,(rem+grid[i][j])%k,dp);
        ans%=mod;
        ans+=f(i,j+1,grid,k,(rem+grid[i][j])%k,dp);
        ans%=mod;
        return dp[i][j][rem]=ans;
        
    }
    int numberOfPaths(vector<vector<int>>& grid, int k)
    {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(100,-1)));
        int ans=f(0,0,grid,k,0,dp);
        return ans;
    }
};