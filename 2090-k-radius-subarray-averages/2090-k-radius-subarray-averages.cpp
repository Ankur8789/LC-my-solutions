class Solution {
public:
    typedef long long ll;
    vector<int> getAverages(vector<int>& nums, int k) 
    {
        vector<ll> pref;
        ll n=nums.size();
        ll ps=0;
        for(auto t:nums)
        {
            ps+=t;
            pref.push_back(ps);
        }
        vector<int> ans;
        for(ll i=0;i<n;i++)
        {
            if(i-k<0 || i+k>=n)
            {
                ans.push_back(-1);
            }
            else
            {
                ll a=pref[i+k];
                if(i-k!=0)
                    a-=pref[i-k-1];
                ans.push_back(a/(2*k +1));
            }
        }
        return ans;
    }
        
        
};