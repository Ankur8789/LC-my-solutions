class Solution {
public:
    int minDifference(vector<int>& nums)
    {
        if(nums.size()<=3)
            return 0;
        int n=nums.size();
        sort(begin(nums),end(nums));
        return min({nums.back()-nums[3],nums[n-2]-nums[2],-nums[1]+nums[n-3],nums[n-4]-nums[0]});
        
    }
};