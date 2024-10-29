class Solution {
public:
    vector<vector<int>> dp;
    int f(int i,int j,vector<vector<int>>& grid){
        auto & x = dp[i][j];
        if(x != -1)
            return x;
        int ans = 0;
        if(i - 1 >= 0 && j + 1 < grid[0].size() && grid[i-1][j+1] > grid[i][j])
            ans = max(ans , 1 + f(i-1 , j+1, grid));
        if(i + 1 < grid.size() && j + 1 < grid[0].size() && grid[i+1][j+1] > grid[i][j])
            ans = max(ans , 1 + f(i+1, j+1 , grid));
        if(j + 1 < grid[0].size() && grid[i][j+1] > grid[i][j])
            ans = max(ans , 1 + f(i , j+1 , grid));
        return x = ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        dp.resize(m + 1, vector<int>(n + 1 , -1));
        int ans = 0;
        for(int i=0;i<m;i++){
            ans = max(ans , f(i , 0 , grid));
        }
        return ans;
    }
};