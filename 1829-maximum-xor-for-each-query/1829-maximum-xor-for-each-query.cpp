class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int mb) {
        int n = nums.size();
        vector<int> pref(n);
        pref[0] = nums[0];
        for(int i=1;i<n;i++)
            pref[i] = (pref[i-1] xor nums[i]);
        reverse(begin(pref), end(pref));
        vector<int> ans;
        for(auto x : pref){
            int val = x;
            int res = 0;
            for(int i=mb-1;i>=0;i--){
                if((val>>i)&1)
                    continue;
                res |= (1<<i);
            }
            ans.push_back(res);
        }
        return ans;
    }
};