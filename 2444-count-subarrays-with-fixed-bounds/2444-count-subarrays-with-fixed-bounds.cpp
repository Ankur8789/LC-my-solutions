class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int min_pos = -1;
        int max_pos = -1;
        int cnt = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==minK) min_pos = i;
            if(nums[i]==maxK) max_pos = i;
            if((nums[i]<minK) || (nums[i]>maxK)) {
                min_pos = -1;
                max_pos = -1;
                cnt = 0;
            } else {
                cnt++;
            }
            if(min_pos!=-1 && max_pos!=-1) {
                ans += min(min_pos, max_pos) - (i - cnt);
            }       
        }
        return ans;
    }
};
