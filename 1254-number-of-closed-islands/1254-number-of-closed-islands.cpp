class Solution {
public:
    int vis[301][301];
    bool hai;
    bool isvalid(int i,int j,vector<vector<int>>& grid)
    {
       if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
           return false;
         if(vis[i][j]==1 || grid[i][j]==1)
             return false;
        return true;
    }
    void dfs(int i,int j,vector<vector<int>>& grid)
    {
        vis[i][j]=1;
        if(i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1)
            hai=true;
        if(isvalid(i+1,j,grid))
            dfs(i+1,j,grid);
        if(isvalid(i-1,j,grid))
            dfs(i-1,j,grid);
        if(isvalid(i,j+1,grid))
            dfs(i,j+1,grid);
        if(isvalid(i,j-1,grid))
            dfs(i,j-1,grid);
    }
    int closedIsland(vector<vector<int>>& grid) 
    {
         int cc=0;
        hai=false;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(isvalid(i,j,grid))
                {
                    dfs(i,j,grid);
                    if(!hai)
                    cc++;
                    hai=false;
                }
            }
        }
        return cc;
        
    }
};