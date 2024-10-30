class Solution {
public:
    int dp[1001][1005][2][2][2];
    int f(int i,int last,int parity,vector<int>& nums,int fst,int sec){
        if(i == nums.size()){
            if(fst && sec &&  parity)
                return 0;
            else
                return -1e9;
        }
        auto & x = dp[i][last + 1][parity][fst][sec];
        if(x != -1)
            return x;
        int ans = -1e9;
        if(last == -1){
            ans = max(ans , f(i+1,last,parity,nums,fst,sec));
            ans = max(ans , 1 + f(i+1 , i , parity,nums,fst|1,sec));
        }
        else{
            if(parity){
                if(nums[last] > nums[i]){
                    ans = max(ans , 1 + f(i+1,i,parity,nums,fst,sec|1));
                }
                ans = max(ans ,  f(i+1,last,parity,nums,fst , sec));
            }
            else{
                if(nums[i] > nums[last]){
                    ans = max(ans , 1 + f(i+1 , i , parity , nums , fst | 1 , sec));
                    ans = max(ans , 1 + f(i+1 , i , 1  , nums, fst | 1 , sec));
                }
                ans = max(ans , f(i+1, last , parity , nums , fst , sec));
            }
        }
        return x = ans;
    }
    int minimumMountainRemovals(vector<int>& nums) {
       memset(dp , -1 , sizeof(dp));
       int ans = f(0,-1,0,nums,0,0);
       return nums.size() - ans;
    }
};