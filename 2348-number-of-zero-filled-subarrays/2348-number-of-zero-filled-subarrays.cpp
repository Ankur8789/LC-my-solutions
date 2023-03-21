class Solution {
public:
    typedef long long ll;
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        vector<ll> v;
        ll cc=0;
        for(auto t: nums)
        {
            if(t==0)
                cc++;
            else
            {   
                v.push_back(cc);
                cc=0;
            }
        }
        if(cc>0)
            v.push_back(cc);
        ll ans=0;
        for(auto t:v)
        {
            ans+=(t*(t+1))/2;
        }
        return ans;
    }
};