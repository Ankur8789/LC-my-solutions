class Solution {
public:
    vector<pair<int,int>> dirs={{0,-1},{0,1},{1,0},{-1,0}};
    bool check(int x,int y,vector<vector<int>>& grid)
    {
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size())
            return 0;
        return 1;
    }
    int minimumObstacles(vector<vector<int>>& grid) 
    {
        multiset<vector<int>> ms;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dis(m,vector<int>(n,1e9));
        if(grid[0][0]==0)
            dis[0][0]=0;
        else
            dis[0][0]=1;
        ms.insert({dis[0][0],0,0});
        while(ms.size()>0)
        {
            auto t=*ms.begin();
            ms.erase(ms.begin());
            int i=t[1];
            int j=t[2];
            int dist=t[0];
            for(auto p:dirs)
            {
                int x=i+p.first;
                int y=j+p.second;
                if(check(x,y,grid))
                {
                    if(grid[x][y]==1)
                    {
                       if(dist+1<dis[x][y])
                       {
                           if(ms.count({dis[x][y],x,y}))
                               ms.erase({dis[x][y],x,y});
                           dis[x][y]=dist+1;
                           ms.insert({dis[x][y],x,y});
                       }
                    }
                    else
                    {
                        if(dist<dis[x][y])
                        {
                            if(ms.count({dis[x][y],x,y}))
                               ms.erase({dis[x][y],x,y});
                           dis[x][y]=dist;
                           ms.insert({dis[x][y],x,y});
                        }
                    }
                }
            }
            
        }
        return dis[m-1][n-1];
    }
};