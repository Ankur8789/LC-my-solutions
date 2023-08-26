class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        unordered_map<int,int> mp,vis;
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i]-k)!=mp.end() && vis.find(nums[i]-k)==vis.end())
            {
                ans+=1;
                vis[nums[i]-k]=1;
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};