class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) 
    {
        map<int,int> mp;
        for(auto t: nums)
            mp[t]+=1;
        int ans=0;
        for(auto t: mp)
        {
            int val=t.second;
            ans+=(val-1)*val/2;
        }
        return ans;
    }
};