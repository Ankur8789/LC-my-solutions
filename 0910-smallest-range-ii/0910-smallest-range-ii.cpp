class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mx=nums[n-1]-k;
        int mn=nums[0]+k;
        int ans=nums[n-1]-nums[0];
        for(int i=0;i<n-1;i++)
        {
            mx=max(nums[n-1]-k,nums[i]+k);
            mn=min(nums[0]+k,nums[i+1]-k);
            ans=min(ans,abs(mx-mn));
        }
        return ans;
      
    }
};