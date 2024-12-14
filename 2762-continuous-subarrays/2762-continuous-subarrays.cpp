class Solution {
public:
    typedef long long ll;
    long long continuousSubarrays(vector<int>& nums) {
        multiset<ll> ms;
        ll ans=0,i=0,j=0,n=nums.size();
        while(j<n){
            ms.insert(nums[j]);
            while(*ms.rbegin()-*ms.begin()>2){
                ms.erase(ms.find(nums[i]));
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};