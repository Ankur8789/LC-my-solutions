class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> pref(300005);
        for (int x : nums) {
            pref[x-k+100000]++;
            pref[(x+k+1+100000)]--;
        }
        for (int i=1; i<300005; i++)
            pref[i] += pref[i-1];
        return *max_element(pref.begin(), pref.end());
    }
};