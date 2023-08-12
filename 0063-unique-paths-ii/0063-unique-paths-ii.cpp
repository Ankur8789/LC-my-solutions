class Solution {
public:
    int dp[101][101];
    int f(int i,int j,vector<vector<int>>& grid)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return 0;
        if(grid[i][j]==1)
            return 0;
        if(i==grid.size()-1 && j==grid[0].size()-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=0;
        ans+=f(i+1,j,grid);
        ans+=f(i,j+1,grid);
        return dp[i][j]=ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obs) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=f(0,0,obs);
        return ans;
    }
};