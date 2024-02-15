class Solution {
public:
    typedef long long ll;
    long long largestPerimeter(vector<int>& nums) 
    {
        sort(begin(nums),end(nums));
        ll n=nums.size();
        vector<ll> pref(n);
        ll ps=0;
        for(ll i=0;i<n;i++)
            ps+=nums[i],pref[i]=ps;
        ll maxi=-1;
        for(ll i=n-1;i>0;i--)
        {
            if(nums[i]>=pref[i-1])continue;
            maxi=max(maxi,1LL*nums[i]+pref[i-1]);
        }
        return maxi;
    }
};