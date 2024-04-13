#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
class Solution
{
public:
    int mah(vector<int> &heights)
    {
        int res = 0, curr = 0, n = heights.size();
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            while (s.empty() == false && heights[s.top()] >= heights[i])
            {
                int top = s.top();
                s.pop();
                if (s.empty())
                    curr = heights[top] * i;
                else
                    curr = heights[top] * (i - s.top() - 1);
                res = max(curr, res);
            }
            s.push(i);
        }

        while (s.empty() == false)
        {
            int top = s.top();
            s.pop();
            if (s.empty())
                curr = heights[top] * n;
            else
                curr = heights[top] * (n - s.top() - 1);
            res = max(curr, res);
        }
        return res;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        fastio();
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = -1e5;
        vector<int> hs(m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '0')
                    hs[j] = 0;
                else
                    hs[j] += 1;
            }
            ans = max(ans, mah(hs));
        }
        return ans;
    }
};