class Solution {
public:
    int m,n;
    int k;
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis)
    {
        vis[i][j]=k;
        if(i+1<m && grid[i+1][j]==1 && vis[i+1][j]==0)
            dfs(i+1,j,grid,vis);
        if(j+1<n && grid[i][j+1]==1 && vis[i][j+1]==0)
            dfs(i,j+1,grid,vis);
        if(i-1>=0 && grid[i-1][j]==1 && vis[i-1][j]==0)
            dfs(i-1,j,grid,vis);
        if(j-1>=0 && grid[i][j-1]==1 && vis[i][j-1]==0)
            dfs(i,j-1,grid,vis);
    }
//     bool check(int mid,vector<vector<int>>& grid)
//     {
//        int val=1e5;
       
//     }
    int shortestBridge(vector<vector<int>>& grid) 
    {
        int l=0,r=1e5;
        int ans=-1;
         k=2;
         m=grid.size();
         n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                {
                    dfs(i,j,grid,vis);
                    k++;
                }
            }
        }
        vector<pair<int,int>> v1,v2;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==2)
                    v1.push_back({i,j});
                if(vis[i][j]==3)
                    v2.push_back({i,j});
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                cout<<vis[i][j]<<" ";
            cout<<endl;
        }
        int dis=1e9;
        for(int i=0;i<v1.size();i++)
        {
            for(int j=0;j<v2.size();j++)
                dis=min(dis,abs(v1[i].first-v2[j].first)+abs(v1[i].second-v2[j].second));
        }
        return dis-1;
       
    }
};