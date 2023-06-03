class Solution {
public:
    vector<vector<int>>dir = {{0, 1}, {0, -1}, {1, 0}, {1, -1}, {1, 1}, {-1, 0}, {-1, 1}, {-1, -1}};
    bool check(int x,int y,int m,int n,vector<vector<int>>& grid)
    {
        if(x<0 || y<0 || x>=m || y>=n)
            return false;
        if(grid[x][y]==1)
            return false;
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        queue<pair<int,pair<int,int>>> q;
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==1)
            return -1;
        vector<vector<int>> dis(m,vector<int>(n,1e9));
        q.push({1,{0,0}});
        dis[0][0]=1;
        while(q.size()>0)
        {
            auto x=q.front();
            q.pop();
            for(int i=0;i<8;i++)
            {
                int nx=x.second.first+dir[i][0];
                int ny=x.second.second+dir[i][1];
                if(check(nx,ny,m,n,grid) && (dis[nx][ny]>x.first+1))
                {
                    dis[nx][ny]=x.first+1;
                    q.push({dis[nx][ny],{nx,ny}});
                }
            }
        }
        if(dis[m-1][n-1]==1e9)
            return -1;
        return dis[m-1][n-1];
        
    }
};