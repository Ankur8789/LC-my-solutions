class Solution {
public:
    int waysToSplitArray(vector<int>& nums)
    {
        long long int sum=0;
        for(auto t: nums)
            sum+=t;
        int cc=0;
        long long int ps=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            ps+=nums[i];
            sum-=nums[i];
            if(ps>=sum)
                cc++;
        }
        return cc;
    }
};