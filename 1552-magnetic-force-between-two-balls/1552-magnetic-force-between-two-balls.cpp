class Solution {
public:
    typedef long long ll;  
    bool check(ll val,vector<int>& pos, int m)
    {
        ll cnt=1,pre=0;
        for(ll i=1;i<pos.size();i++)
        {
            if(pos[i]-pos[pre]>=val)
            {
                cnt++;
                pre=i;
            }
        }
        return cnt>=m;
    }
    int maxDistance(vector<int>& pos, int m) 
    {
       sort(begin(pos),end(pos));
       ll l=0,r=1e12;
       ll ans=-1;
       while(l<=r)
       {
           ll mid=(l+r)/2;
           if(check(mid,pos,m))
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