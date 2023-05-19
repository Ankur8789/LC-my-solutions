class Solution {
public:
    int li=-1,ri=-1,le=-1,re=-1;
    int vis[301][301];
    void dfs(int i,int j,vector<vector<int>>& land)
    {
        vis[i][j]=1;
        if(i>le)
        {
            le=i;
            re=j;
        }
        else if(le==i)
            re=max(re,j);
        if(i+1<land.size() && land[i+1][j]==1 && vis[i+1][j]==0)
            dfs(i+1,j,land);
        if(j+1<land[0].size() && land[i][j+1]==1 && vis[i][j+1]==0)
            dfs(i,j+1,land);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) 
    {
        int m=land.size();
        int n=land[0].size();
        vector<vector<int>> ans;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==0 && land[i][j]==1)
                {
                    li=i,ri=j;
                    le=i,re=j;
                    dfs(i,j,land);
                    ans.push_back({li,ri,le,re});
                    li=-1,ri=-1,le=-1,re=-1;
                }
            }
        }
        return ans;
    }
};