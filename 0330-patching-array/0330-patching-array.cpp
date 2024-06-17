class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ind = 0, patches=0;
        long max_reach;
        for(max_reach=1;max_reach<=n;){
            if(ind<nums.size() && max_reach>=nums[ind]){
                max_reach = max_reach + nums[ind];
                ind++;
            }
            else{
                patches++;
                max_reach += max_reach;
            }
        }
        return patches;
    }
};