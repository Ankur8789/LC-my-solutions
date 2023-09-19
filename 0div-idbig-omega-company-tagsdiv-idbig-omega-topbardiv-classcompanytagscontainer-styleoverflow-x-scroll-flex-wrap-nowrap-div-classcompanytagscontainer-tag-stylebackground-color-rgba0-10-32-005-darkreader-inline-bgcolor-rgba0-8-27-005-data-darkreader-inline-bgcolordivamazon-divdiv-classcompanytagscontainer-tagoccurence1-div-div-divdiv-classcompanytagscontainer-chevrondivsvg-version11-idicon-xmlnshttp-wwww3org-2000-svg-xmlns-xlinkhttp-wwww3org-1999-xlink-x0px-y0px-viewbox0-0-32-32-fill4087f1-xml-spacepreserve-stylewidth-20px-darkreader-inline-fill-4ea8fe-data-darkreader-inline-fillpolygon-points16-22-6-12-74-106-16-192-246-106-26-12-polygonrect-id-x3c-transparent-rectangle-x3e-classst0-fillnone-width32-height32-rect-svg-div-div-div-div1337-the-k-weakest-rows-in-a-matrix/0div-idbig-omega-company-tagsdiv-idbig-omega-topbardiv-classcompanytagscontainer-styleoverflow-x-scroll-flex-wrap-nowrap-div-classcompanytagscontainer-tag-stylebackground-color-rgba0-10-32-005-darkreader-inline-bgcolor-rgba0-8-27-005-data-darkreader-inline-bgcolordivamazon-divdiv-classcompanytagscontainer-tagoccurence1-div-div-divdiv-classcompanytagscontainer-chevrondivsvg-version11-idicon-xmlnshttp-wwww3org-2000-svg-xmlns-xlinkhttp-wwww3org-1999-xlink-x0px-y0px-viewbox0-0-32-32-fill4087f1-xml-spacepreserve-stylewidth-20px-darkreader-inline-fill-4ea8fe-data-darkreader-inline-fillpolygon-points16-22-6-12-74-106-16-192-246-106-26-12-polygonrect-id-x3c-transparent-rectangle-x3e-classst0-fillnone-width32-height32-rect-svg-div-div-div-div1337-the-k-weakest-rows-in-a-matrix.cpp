class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<pair<int, int>> res;
        for (int i = 0; i < mat.size(); i++)
        {
            int str = accumulate(mat[i].begin(), mat[i].end(), 0);
            res.push_back({str, i});
        }
        sort(res.begin(), res.end());
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(res[i].second);
        }
        return ans;
    }
};