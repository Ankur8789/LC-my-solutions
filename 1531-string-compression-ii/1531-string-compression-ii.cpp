int t[101][27][101][101];
class Solution
{
public:
    int solve(string &s, int i, int prev, int freq, int k)
    {
        if (k < 0)
            return INT_MAX;

        if (i >= s.length())
            return 0;

        auto &ret = t[i][prev][freq][k];
        if (ret != -1)
            return ret;

        int delete_i = solve(s, i + 1, prev, freq, k - 1);

        int keep_i = 0;

        if (s[i] - 'a' == prev)
        {
            int one_more_added = 0;
            if (freq == 1 || freq == 9 || freq == 99)
            {
                one_more_added = 1;
            }
            keep_i = one_more_added + solve(s, i + 1, prev, freq + 1, k);
        }
        else
        {
            keep_i = 1 + solve(s, i + 1, s[i] - 'a', 1, k);
        }

        return ret = min(delete_i, keep_i);
    }

    int getLengthOfOptimalCompression(string s, int k)
    {
        memset(t, -1, sizeof(t));
        return solve(s, 0, 26, 0, k);
    }
};