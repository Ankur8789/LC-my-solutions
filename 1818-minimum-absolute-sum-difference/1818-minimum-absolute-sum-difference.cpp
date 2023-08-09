class Solution {
public:
    typedef long long ll;
    const int mod=1e9+7;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) 
    {
        set<ll> st1;
        for(auto t: nums1)
            st1.insert(t);
        
        ll res=0;
        for(int i=0;i<nums1.size();i++)
        {
            res+=abs(nums1[i]-nums2[i]);
            // res%=mod;
        }
        ll desr=res;
        for(int i=0;i<nums1.size();i++)
        {
            if(abs(nums1[i]-nums2[i])==0)
                continue;
            auto lb=st1.lower_bound(nums2[i]);
            auto ub=st1.upper_bound(nums2[i]);
            ll temp=abs(*lb-nums2[i]);
            ll val=res;
            val-=abs(nums1[i]-nums2[i]);
            // val+=mod;
            // val%=mod;
            val+=temp;
            // val%=mod;
            desr=min(desr,val);
            if(ub!=st1.begin())
            {
                ub--;
                temp=abs(*ub-nums2[i]);
                val=res;
                val-=abs(nums1[i]-nums2[i]);
                // val+=mod;
                // val%=mod;
                val+=temp;
                // val%=mod;
                desr=min(desr,val);
            }
            // cout<<desr<<endl;
        }
        return desr%mod;
    }
};