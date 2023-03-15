class Solution {
public:
    int n,m;
    int cnt=0;
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis)
    {
        if(i<0 || j<0 || i>=m || j>=n)
        return ;
        if(vis[i][j]==1)
            return ;
        if(grid[i][j]==0)
            return;
        vis[i][j]=1;
        cnt++;
        dfs(i+1,j,grid,vis);
        dfs(i-1,j,grid,vis);
        dfs(i,j+1,grid,vis);
        dfs(i,j-1,grid,vis);

    }
    int coc(vector<vector<int>>& grid)
    {
        m=grid.size();
        n=grid[0].size();
        int cc=0;
        vector<vector<int>> vis(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                {
                    dfs(i,j,grid,vis);
                    cc++;
                }
            }
        }
        return cc;
    }
    int minDays(vector<vector<int>>& grid) 
    {    
        cnt=0;
        int cc=coc(grid);
        if(cc>1 || cc<1)
            return 0;
        if(cnt==1)
            return 1;
        if(cnt==2)
            return 2;
        else
        {
           for(int i=0;i<m;i++)
           {
               for(int j=0;j<n;j++)
               {
                   if(grid[i][j]==1)
                   {
                       //vector<vector<int>> vis(m,vector<int>(n));
                      // cout<<i<<" "<<j<<endl;
                       grid[i][j]=0;
                       int ct=coc(grid);
                       grid[i][j]=1;
                       if(ct>1)
                           return 1;
                   }
                   
               }
           }
            return 2;
        }
            
    }
};