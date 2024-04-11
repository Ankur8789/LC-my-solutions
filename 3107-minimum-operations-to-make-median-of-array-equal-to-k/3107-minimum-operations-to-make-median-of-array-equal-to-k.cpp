class Solution {
public:
    typedef long long ll;
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) 
    {
        sort(begin(nums),end(nums));
        ll n = nums.size();
        ll mid = n / 2;
        ll ans = 0;
        if (nums[mid] == k) 
            return 0;
        else if (nums[mid] < k) 
            ans = k - nums[mid];
        else 
            ans = nums[mid] - k;
        for (int i = mid-1; i >= 0 && nums[i] > k; i--)
            ans += nums[i] - k;
        for (int i = mid+1; i < n && nums[i] < k; i++) 
            ans += k - nums[i];

        return ans;
        
    }
};