class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<int, int> um;
        for (int i : arr1)
        {
            um[i]++;
        }
        unordered_set<int> st;
        for (int i : arr2)
        {
            st.insert(i);
        }
        vector<int> res, extra;
        for (int i : arr2)
        {
            if (um.find(i) != um.end())
            {
                int k = um[i];
                while (k--)
                {
                    res.push_back(i);
                }
                um[i] = 0;
            }
        }
        for (int i : arr1)
        {
            if (st.find(i) == st.end())
            {
                extra.push_back(i);
            }
        }
        sort(extra.begin(), extra.end());
        for (int i : extra)
        {
            res.push_back(i);
        }
        return res;
    }
};