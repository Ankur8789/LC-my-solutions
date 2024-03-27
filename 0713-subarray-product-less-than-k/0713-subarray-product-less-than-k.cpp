class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0)
            return 0;

        int n = nums.size(), count = 0, l = 0, r = 0, product = 1;
        while (r < n) 
        {
            product *= nums[r];
           
            while (l <= r && product >= k) 
            {
                product /= nums[l++]; 
            }

            count += ++r - l;
        }
        
        return count;
    }
};