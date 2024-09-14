class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int ele=*max_element(begin(nums),end(nums));
       int maxi=0,cnt=0;
       for(auto x: nums){
           if(x==ele)
               cnt++;
           else
               cnt=0;
           maxi=max(maxi,cnt);
       }
       return maxi;
    }
};