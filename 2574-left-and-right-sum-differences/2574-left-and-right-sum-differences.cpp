class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) 
    {
        int lsum=0,rsum=0;
        for(auto t: nums)rsum+=t;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            rsum-=nums[i];
            ans.push_back(abs(lsum-rsum));
            lsum+=nums[i];
        }
        return ans;
    }
};