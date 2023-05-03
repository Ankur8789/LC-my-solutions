class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<vector<int>> ans(2);
        map<int,int> m1,m2;
        for(auto t:nums1)
            m1[t]++;
        for(auto t:nums2)
            m2[t]++;
        map<int,int> vis;
        for(auto t:nums1)
        {
            if(vis[t]==1)
                continue;
            else
            {
                if(m2.find(t)==m2.end())
                {
                    ans[0].push_back(t);
                    vis[t]++;
                }
            }
        }
        vis.clear();
         for(auto t:nums2)
        {
            if(vis[t]==1)
                continue;
            else
            {
                if(m1.find(t)==m1.end())
                {
                    ans[1].push_back(t);
                    vis[t]++;
                }
            }
        }
        return ans;
        
    }
};