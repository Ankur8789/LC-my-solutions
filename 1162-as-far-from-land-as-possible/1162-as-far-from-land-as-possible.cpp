class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,-1));
        vector<vector<int>> res(n,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    res[i][j]=0;
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        int dx[4]={1,0,0,-1};
        int dy[4]={0,-1,1,0};
        while(q.size()>0)
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
             for(int i=0;i<4;i++)
             {
                 int X=x+dx[i];
                 int Y=y+dy[i];
                 if(X>=0 && Y>=0 && X<n && Y<n && vis[X][Y]==-1)
                 {
                     q.push({X,Y});
                     vis[X][Y]=1;
                     res[X][Y]=res[x][y]+1;
                     
                 }
                    
             }
        }
        int max=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(res[i][j]>max)
                    max=res[i][j];
            }
        }
        if(max==0) return -1;
        return max;
        
    }
};