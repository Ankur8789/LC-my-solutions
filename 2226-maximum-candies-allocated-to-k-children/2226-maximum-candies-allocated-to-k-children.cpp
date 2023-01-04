class Solution {
public:
    typedef long long ll;
    bool check(ll mid,vector<int>& c,ll k)
    { //if(mid==0)
    //     return true;
        ll cnt=0;
        for(int i=0;i<c.size();i++)
            cnt+=(c[i]/mid);
         if(cnt>=k)
             return true;
        else
            return false;
    }
    int maximumCandies(vector<int>& c, long long k) 
    {   int mn=INT_MIN;
       for(int i=0;i<c.size();i++)
         mn=max(mn,c[i]);
        ll l=1,r=mn;
         ll ans=0;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            //cout<<mid<<endl;
            if(check(mid,c,k))
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return ans;     
    }
};