class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        unordered_map<int,int> mp,vis;
        vector<int> ans;
        for(auto t: nums)
            mp[t]++;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]]>(n/3))
            {
                if(vis.find(nums[i])==vis.end())
                {
                    ans.push_back(nums[i]);
                    vis[nums[i]]=1;
                }
            }
        }
        return ans;
        
    }
};