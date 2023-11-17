class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        unordered_map<int,int> mp;
        int ans=0;
        mp[0]++;
        int n=nums.size();
        int ps=0;
        for(int i=0;i<n;i++)
        {
            ps+=nums[i];
            if(mp.find(ps-goal)!=mp.end())
                ans+=mp[ps-goal];
            mp[ps]++;
        }
        return ans;
    }
};