#define fi first
#define se second
class Solution {
public:
    vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
    int minTimeToReach(vector<vector<int>>& v) {
        int m = v.size() , n = v[0].size();
        int dis[m][n][2];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<2;k++){
                    dis[i][j][k]=INT_MAX;
                }
            }
        }
        // vector<vector<int>> sg = dis;
        multiset<vector<int>> ms;
        dis[0][0][0] = 0;
        // sg[0][0] = 0;
        ms.insert({dis[0][0][0],0,0,0});
        // dis move xpos ypos
        while(ms.size()){
            auto vec = *ms.begin();
            ms.erase(ms.begin());
            int d = vec[0] , mov = vec[1] , x = vec[2] , y = vec[3];
            for(auto p : dirs){
                int nx = x + p.fi , ny = y + p.se;
                if(nx < 0 || ny < 0 || nx >= m || ny >= n )
                    continue;
                int nxtmov = mov ^ 1;
                if(dis[nx][ny][nxtmov] > max(v[nx][ny],d ) + mov + 1){
                    dis[nx][ny][nxtmov] = max(v[nx][ny],d ) + mov + 1;
                    ms.insert({dis[nx][ny][nxtmov] , nxtmov , nx , ny});
                }
            }
        }
        return min(dis[m-1][n-1][0] , dis[m-1][n-1][1]);
    }
};