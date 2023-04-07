class Solution {
public:
    int vis[501][501];
    bool check(int i,int j,vector<vector<int>>& grid)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return false;
        if(grid[i][j]==0 || vis[i][j]==1)
            return false;
        return true;
            
    }
    void dfs(int i,int j,vector<vector<int>>& grid)
    {
        vis[i][j]=1;
        if(check(i+1,j,grid))
            dfs(i+1,j,grid);
        if(check(i-1,j,grid))
            dfs(i-1,j,grid);
        if(check(i,j+1,grid))
            dfs(i,j+1,grid);
        if(check(i,j-1,grid))
            dfs(i,j-1,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==0 || i==m-1 || j==n-1)
                {
                    if(vis[i][j]==0 && grid[i][j]==1)
                        dfs(i,j,grid);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==0 && grid[i][j]==1)
                    cnt++;
            }
        }
        return cnt;
    }
};