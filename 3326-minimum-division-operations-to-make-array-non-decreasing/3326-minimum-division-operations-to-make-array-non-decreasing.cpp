
class Solution {
public:
    int soe(int val){
        int maxi = 1;
        for(int i=2;i*i<=val;i++){
            if(val%i==0){
                maxi = max(maxi , i);
                maxi = max(maxi , val/i);
            }
        }
        return maxi;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size() , ans = 0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                int val = nums[i];
                int cnt = 0;
                while(val > nums[i+1]){
                   int div = soe(val);
                   if(div == 1)
                       break;
                   val /= div;
                    cnt += 1;
                }
                if(val > nums[i+1])
                    return -1;
                nums[i] = val;
                ans += cnt;
            }
        }
        return ans;
    }
};