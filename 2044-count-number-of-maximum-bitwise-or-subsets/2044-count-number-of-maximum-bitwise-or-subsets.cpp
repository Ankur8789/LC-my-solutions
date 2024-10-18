class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi=0;
        for(auto x: nums)
            maxi |= x;
        int cnt=0;
        int n = nums.size();
        for(int i=0;i<(1<<n);i++){
            int val = i;
            int pxor = 0;
            for(int j=0;j<n;j++){
                if((val>>j)&1){
                    pxor |= nums[j];
                }
            }
            if(pxor == maxi)
                cnt++;
        }
        return cnt;
    }
};