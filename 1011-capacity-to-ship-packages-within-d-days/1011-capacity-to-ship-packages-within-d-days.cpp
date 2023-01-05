class Solution {
public:
    
    typedef long long ll;
    bool check(ll mid,vector<int>& w,int d)
    {
        ll cc=0,sum=0;
        for(auto t: w)
        {  if(t>mid)
            return false;
            sum+=t;
            if(sum>mid)
            {
               cc++;
                sum=t;
            }
        }
        if(sum)
            cc++;
        return cc<=d;
    }
    int shipWithinDays(vector<int>& w, int d) 
    {
        ll l=1,r=1e10;
        ll ans=-1;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(check(mid,w,d))
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