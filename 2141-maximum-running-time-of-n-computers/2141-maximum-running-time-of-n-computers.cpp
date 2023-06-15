class Solution {
public:
    typedef long long ll;
    bool check(ll mid,int n,vector<int>& bat)
    {
       ll cc=0;
       ll ps=0;
       for(auto t: bat)
       {
           ps+=t;
           if(ps==mid)
           {
               cc++;
               ps=0;
           }
           else if(ps>mid)
           {
               cc++;
               ps-=mid;
           }
       }
       return cc>=n; 
    }
    long long maxRunTime(int n, vector<int>& bat){
        ll ans=-1;
        ll l=0,r=1e18;
        sort(bat.begin(),bat.end());
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(check(mid,n,bat))
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