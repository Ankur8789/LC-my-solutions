class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &v)
    {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < v.size(); i++)
        {
            if (mp.find(v[i]) == mp.end())
            {
                mp[v[i]] = {i};
            }
            else
            {
                mp[v[i]].push_back(i);
            }
        }

        for (auto &it : mp)
        {
            int groupSize = it.first;
            vector<int> &groupMembers = it.second;

            for (int i = 0; i < groupMembers.size(); i += groupSize)
            {
                vector<int> subgroup;
                for (int j = i; j < i + groupSize; j++)
                {
                    subgroup.push_back(groupMembers[j]);
                }
                res.push_back(subgroup);
            }
        }
        return res;
    }
};