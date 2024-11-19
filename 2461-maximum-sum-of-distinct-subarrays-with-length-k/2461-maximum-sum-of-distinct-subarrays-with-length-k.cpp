class Solution {
public:
    typedef long long ll;
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ll ans=0,sum=0,i=0,j=0,n=nums.size();
        map<ll,ll> mp;
        while(j<n){
            mp[nums[j]]+=1;
            sum+=nums[j];
            if(j-i+1<k)
                j++;
            else if(j-i+1==k){
                if(mp.size()==k){
                    ans=max(ans,sum);
                }
                sum-=nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};