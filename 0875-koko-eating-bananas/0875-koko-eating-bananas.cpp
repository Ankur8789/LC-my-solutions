class Solution {
public:
    typedef long long ll;
    bool check(ll mid,vector<int>& v,ll h)
    {
        ll cc=0;
        for(ll i=0;i<v.size();i++)
        {
            cc+=(v[i]/mid);
            if(v[i]%mid!=0)
                cc++;
        }
        if(cc<=h)
            return true;
        else
            return false;
    }
    int minEatingSpeed(vector<int>& v, int h) 
    {
        ll l=1,r=1e10;
        ll ans=INT_MAX;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(check(mid,v,h))
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};