class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
       for(auto& t: nums)
           t=t*t;
        sort(begin(nums),end(nums));
        return nums;
    }
};