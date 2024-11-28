class Solution {
public:
    vector<pair<int,int>> dirs={{0,1},{0,-1},{-1,0},{1,0}};
    bool check(int x,int y,vector<vector<int>>& grid){
        if(x>=grid.size() || y>=grid[0].size() || x<0 ||y<0)
            return 0;
        return 1;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        multiset<vector<int>> ms;
        int m=grid.size(),n=grid[0].size();
        int dis[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dis[i][j]=1e9;
            }
        }
        dis[0][0]=0;
        ms.insert({0,0,0});
        // d x y
        while(ms.size()){
            auto x=*ms.begin();
            ms.erase(ms.begin());
            int d=x[0],i=x[1],j=x[2];
            for(auto t: dirs){
                int nx=i+t.first,ny=j+t.second;
                if(check(nx,ny,grid)){
                    int p=0;
                    if(grid[nx][ny]==1)
                        p++;
                    if(dis[nx][ny]>d+p){
                        if(ms.count({dis[nx][ny],nx,ny}))
                            ms.erase({dis[nx][ny],nx,ny});
                        dis[nx][ny]=d+p;
                        ms.insert({dis[nx][ny],nx,ny});
                    }
                }
            }
        }
        return dis[m-1][n-1];
    }
};