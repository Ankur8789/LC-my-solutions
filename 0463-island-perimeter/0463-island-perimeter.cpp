class Solution {
public:
    vector<vector<int>> vis;
    vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    int dfs(int i , int j , vector<vector<int>>& grid)
    {
        if(i<0 || j<0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return 1;
        if(vis[i][j])
            return 0;
        vis[i][j] = 1;
        int ans = 0;
        for(auto t: dirs)
        {
            int x = i + t.first;
            int y = j + t.second;
            ans += dfs(x , y ,grid);
        }
        return ans;
        
    }
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vis.resize(m , vector<int>(n));
        for(int i = 0;i< m ;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(vis[i][j] == 0 && grid[i][j])
                {
                    ans += dfs(i , j , grid);
                }
            }
        }
        return ans;
    }
};