class Solution {
public:
    const int mod=1e9+7;
    typedef long long ll;
    int countHomogenous(string s) 
    {
        int ans=0;
        for(char ch='a';ch<='z';ch++)
        {
            ll cnt=0;
            for(auto t: s)
            {
                if(t==ch)
                    cnt++;
                else
                {
                    ll res=(cnt*(cnt+1))/2;
                    res%=mod;
                    ans+=res;
                    ans%=mod;
                    cnt=0;
                }
            }
            if(cnt>0)
            {
                ll res=(cnt*(cnt+1))/2;
                res%=mod;
                ans+=res;
                ans%=mod;
            }
        }
        return ans;
    }
};