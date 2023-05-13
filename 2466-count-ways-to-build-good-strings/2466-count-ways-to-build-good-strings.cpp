class Solution {
public:
    const int m=1e9+7;
    typedef long long ll;
     ll hey=0;
    ll t[100001];
        
    ll f(int l,int h,int z,int o,int sz)
    {
        if(sz+z>h && sz+o>h)
        {
            if(sz>=l && sz<=h)
                return 1;
            else
                return 0;
        }
       
        if(t[sz]!=-1)
            return t[sz];
        ll a=0,b=0;
        if(sz+z<=h)
            a=f(l,h,z,o,sz+z)%m;
        if(sz+o<=h)
            b=f(l,h,z,o,sz+o)%m;
        if(sz<=h && sz>=l)
        return t[sz]=1+(a+b)%m;
        else
            return t[sz]=(a+b)%m;
            
    }
    int countGoodStrings(int low, int high, int zero, int one) 
    { memset(t,-1,sizeof(t));
       ll ans=f(low,high,zero,one,0);
        return (ans+hey)%m;
    }
};