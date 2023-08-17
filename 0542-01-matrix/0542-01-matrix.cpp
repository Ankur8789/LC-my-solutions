class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> t = mat;

        queue<pair<int, int>> q;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 0)
                {
                    t[i][j] = 1;
                    q.push({i, j});
                }
                else
                    t[i][j] = 0;
            }
        }

        while (q.size() > 0)
        {
            pair<int, int> p = q.front();
            int x = p.first;
            int y = p.second;
            q.pop();
            if (x + 1 < m && mat[x + 1][y] == 1 && t[x + 1][y] == 0)
            {
                t[x + 1][y] = 1;
                q.push({x + 1, y});
                mat[x + 1][y] = mat[x][y] + 1;
            }
            if (x - 1 >= 0 && mat[x - 1][y] == 1 && t[x - 1][y] == 0)
            {
                t[x - 1][y] = 1;
                q.push({x - 1, y});
                mat[x - 1][y] = 1 + mat[x][y];
            }
            if (y + 1 < n && mat[x][y + 1] == 1 && t[x][y + 1] == 0)
            {
                t[x][y + 1] = 1;
                q.push({x, y + 1});
                mat[x][y + 1] = 1 + mat[x][y];
            }
            if (y - 1 >= 0 && mat[x][y - 1] == 1 && t[x][y - 1] == 0)
            {
                t[x][y - 1] = 1;
                q.push({x, y - 1});
                mat[x][y - 1] = 1 + mat[x][y];
            }
        }
        return mat;
    }
};