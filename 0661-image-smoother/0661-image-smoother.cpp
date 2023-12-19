class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int delRow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int delCol[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int cnt = 1, temp = img[i][j];
                for (int k = 0; k < 8; k++)
                {
                    int r = i + delRow[k];
                    int c = j + delCol[k];
                    if (r >= 0 && r < m && c >= 0 && c < n)
                    {
                        temp += img[r][c];
                        cnt++;
                    }
                }
                temp /= cnt;
                res[i][j] = temp;
            }
        }
        return res;
    }
};