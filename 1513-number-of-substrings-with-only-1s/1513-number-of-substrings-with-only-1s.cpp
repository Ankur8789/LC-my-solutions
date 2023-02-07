class Solution {
public:
    typedef long long ll;
    const ll mod=1e9+7;
    int numSub(string s) 
    {
        ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
        ll cnt=0,zr=0,i=0,j=0,n=s.length();
        while(j<n)
        {
            if(s[j]=='0')
                zr++;
            while(zr>0)
            {
                if(s[i]=='0')
                    zr--;
                i++;
            }
           cnt=(cnt+(j-i+1))%mod;
            j++;
        }
        return cnt;
    }
};