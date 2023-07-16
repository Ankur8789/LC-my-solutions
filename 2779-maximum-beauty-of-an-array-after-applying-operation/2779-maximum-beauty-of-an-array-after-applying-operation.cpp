class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) 
    {
         int val = 100000;
        vector<int> fre(300005);
        for (int i = 0; i < nums.size(); i++) {
            fre[nums[i] - k + val]++;
            fre[nums[i] + k + val + 1]--;
        }
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < 300005; i++) {
            sum += fre[i];
            ans = std::max(ans, sum);
        }
    
        return ans;
        
    }
};