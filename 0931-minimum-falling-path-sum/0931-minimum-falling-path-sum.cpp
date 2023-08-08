class Solution
{
public:
    
    int solve(vector<vector<int>> &matrix, int row, int col,vector<vector<int>>& dp)
    {
        if (col < 0 || col > matrix.size() - 1)
            return INT_MAX;
        if (row == matrix.size() - 1)
            return matrix[row][col];
        if (dp[row][col] != INT_MIN)
            return dp[row][col];

        int t1 = INT_MAX, t2 = INT_MAX, t3 = INT_MAX;

        t1 = solve(matrix, row + 1, col - 1,dp);

        t2 = solve(matrix, row + 1, col,dp);

        t3 = solve(matrix, row + 1, col + 1,dp);

        return dp[row][col] = matrix[row][col] + min({t1, t2, t3});
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        // memset(dp, -1, sizeof(dp));
        vector<vector<int>> dp(n,vector<int>(n,INT_MIN));
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
            ans = min(ans, solve(matrix, 0, i,dp));
        return ans;
    }
};