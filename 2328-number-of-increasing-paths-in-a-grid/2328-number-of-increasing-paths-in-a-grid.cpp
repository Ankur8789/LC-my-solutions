class Solution {
public:
    const int mod=1e9+7;
    vector<pair<int,int>> dir ={{0,1},{0,-1},{1,0},{-1,0}};
    int dp[1001][1001];
    bool check(int i,int j,int m,int n)
    {
        if(i<0 || j<0 ||i>=m || j>=n)
            return false;
        return true;
    }
    int f(int i,int j,int m,int n,vector<vector<int>>& grid)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=1;
        for(auto t: dir)
        {
            if(check(i+t.first,j+t.second,m,n) && grid[i+t.first][j+t.second]>grid[i][j])
            {
                ans+=f(i+t.first,j+t.second,m,n,grid);
                ans%=mod;
            }
        }
        return dp[i][j]=ans;
        
    }
    int countPaths(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans+=f(i,j,m,n,grid);
                ans%=mod;
            }
        }
        return ans;
    }
};