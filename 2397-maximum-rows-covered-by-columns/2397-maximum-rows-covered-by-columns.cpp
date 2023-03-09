class Solution
{
public:
    int ppc(int n)
    {
        int c = 0;
        for (; n; ++c)
            n &= n - 1;
        return c;
    }
    int maximumRows(vector<vector<int>> &matrix, int numSelect)
    {
        int maxans = -1;
        int m = matrix.size();
        int n = matrix[0].size();

        for (int mask = 0; mask < (1 << n); mask++)
        {
            int cnt = 0;
            // cout<<mask<<endl;
            if (ppc(mask) > numSelect)
                continue;
            // cout<<mask<<endl;
            for (int i = 0; i < m; i++)
            {
                int tmp = 0, tc = 0;
                for (int j = 0; j < n; j++)
                {
                    if (matrix[i][j] == 1)
                    {
                        tc++;
                        if ((mask >> j) & 1)
                            tmp++;
                    }
                }
                if (tmp == tc)
                {
                    ++cnt;
                    // cout<<i<<" ";
                }
                // cout<<endl;
            }
            maxans = max(maxans, cnt);
        }
        return maxans;
    }
};