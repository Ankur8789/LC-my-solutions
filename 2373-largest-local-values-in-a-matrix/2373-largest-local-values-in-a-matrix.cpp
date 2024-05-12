class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> arr(n - 2, vector<int>(n - 2, 0));
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                arr[i - 1][j - 1] = max({grid[i][j], grid[i - 1][j - 1], grid[i + 1][j + 1], grid[i - 1][j], grid[i - 1][j + 1], grid[i][j - 1], grid[i][j + 1], grid[i + 1][j], grid[i + 1][j - 1]});
            }
        }
        return arr;
    }
};