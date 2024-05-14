class Solution {
public:
    int mx;
    int vis[16][16];
    bool check(int i,int j,vector<vector<int>>& grid)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
         return false;
        if(vis[i][j]==1)
            return false;
        if(grid[i][j]==0)
            return false;
        return true;
    }
    int f(int i,int j,vector<vector<int>>& grid)
    {
        vis[i][j]=1;
        int ans=0;
        if(check(i+1,j,grid))
            ans=max(ans,f(i+1,j,grid));
        if(check(i-1,j,grid))
            ans=max(ans,f(i-1,j,grid));
        if(check(i,j+1,grid))
            ans=max(ans,f(i,j+1,grid));
        if(check(i,j-1,grid))
            ans=max(ans,f(i,j-1,grid));
         vis[i][j]=0;
        return grid[i][j]+ans;
        
    }
    int getMaximumGold(vector<vector<int>>& grid) 
    {  
     int res=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                mx=f(i,j,grid);
                res=max(res,mx);
            }
        }
     return res;
    }
};