class Solution {
public:
    int findMaxK(vector<int>& nums)
    {
        sort(begin(nums) , end(nums));
        reverse(begin(nums) , end(nums));
        map<int , int> mp;
        for(auto x : nums)
            mp[x] += 1;
        for(auto x : nums)
        {
            if(mp.count(-1*x))
                return x;
        }
        return -1;
    }
};