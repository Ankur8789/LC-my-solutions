class Solution {
public:
    int minPairSum(vector<int>& nums) 
    {
       sort(begin(nums),end(nums));
       int maxi=0;
       int n=nums.size();
       for(int i=0;i<n/2;i++)
           maxi=max(maxi,nums[i]+nums[n-1-i]);
       return maxi;
    }
};