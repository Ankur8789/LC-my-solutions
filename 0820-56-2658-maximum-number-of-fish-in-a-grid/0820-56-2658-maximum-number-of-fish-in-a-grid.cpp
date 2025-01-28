class Solution {
public:
    int vis[11][11];
    vector<pair<int,int>> dirs={{-1,0},{1,0},{0,1},{0,-1}};
    void dfs(int i,int j,vector<vector<int>>& v,int& res){
        vis[i][j]=1;
        res+=v[i][j];
        for(auto t: dirs){
            int x=i+t.first,y=j+t.second;
            if(x>=0 && y>=0 && x<v.size() && y<v[0].size() && vis[x][y]==0 && v[x][y]>0){
                dfs(x,y,v,res);
            }
        }
    }
    int findMaxFish(vector<vector<int>>& v) {
        int m=v.size(),n=v[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vis[i][j]=0;
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]>0 && vis[i][j]==0){
                    int res=0;
                    dfs(i,j,v,res);
                    ans=max(ans,res);
                }
            }
        }
        return ans;
    }
};