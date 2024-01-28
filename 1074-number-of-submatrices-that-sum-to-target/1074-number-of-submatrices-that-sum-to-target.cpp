vector<vector<int>> ps2d(vector<vector<int>> &a)
{
    int R = a.size();
    int C = a[0].size();
    vector<vector<int>> psa(R, vector<int>(C));
    psa[0][0] = a[0][0];
    for (int i = 1; i < C; i++)
        psa[0][i] = psa[0][i - 1] + a[0][i];
    for (int i = 1; i < R; i++)
        psa[i][0] = psa[i - 1][0] + a[i][0];
    for (int i = 1; i < R; i++)
    {
        for (int j = 1; j < C; j++)
            psa[i][j] = psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1] + a[i][j];
    }
    return psa;
}
class Solution
{
public:
    // ps on a 2-d grid
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> psa = ps2d(matrix);
        for (int x1 = 0; x1 < m; x1++)
        {
            for (int x2 = x1; x2 < m; x2++)
            {
                for (int y1 = 0; y1 < n; y1++)
                {
                    for (int y2 = y1; y2 < n; y2++)
                    {

                        int sum = psa[x2][y2];
                        if (y1 != 0)
                        {
                            sum -= psa[x2][y1 - 1];
                        }
                        if (x1 != 0)
                        {
                            sum -= psa[x1 - 1][y2];
                            if (y1 != 0)
                            {
                                sum += psa[x1 - 1][y1 - 1];
                            }
                        }
                        if (sum == target)
                        {
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};