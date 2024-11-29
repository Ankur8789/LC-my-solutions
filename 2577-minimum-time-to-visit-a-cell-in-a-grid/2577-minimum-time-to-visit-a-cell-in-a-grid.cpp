class Solution {
public:
    vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
    bool check(int x,int y,int m,int n){
        if(x<0 || y<0 || x>=m || y>=n)
            return 0;
        return 1;
    }
    int minimumTime(vector<vector<int>>& grid) {
         if(grid[0][1]>grid[0][0]+1 && grid[1][0]>1)
            return -1;
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dis(m,vector<int>(n,1e9));
        dis[0][0]=0;
        multiset<vector<int>> ms;
        ms.insert({dis[0][0],0,0});
        while(ms.size()){
            auto p=*ms.begin();
            ms.erase(ms.begin());
            int d=p[0],x=p[1],y=p[2];
            bool move=false;
            for(auto t: dirs){
                int nx=x+t[0],ny=y+t[1];
                if(check(nx,ny,m,n)){
                    if(d+1<grid[nx][ny]){
                        int val=grid[nx][ny];
                        if((val+d+1)&1)
                            val++;
                        if(val<dis[nx][ny]){
                            dis[nx][ny]=val;;
                            ms.insert({val,nx,ny});
                        }
                    }
                    else{
                        if(d+1<dis[nx][ny]){
                            dis[nx][ny]=d+1;
                            ms.insert({dis[nx][ny],nx,ny});
                        }
                    }
                }
            }
            
        }
        if(dis[m-1][n-1]==1e9)
            return -1;
        return dis[m-1][n-1];
    }
};