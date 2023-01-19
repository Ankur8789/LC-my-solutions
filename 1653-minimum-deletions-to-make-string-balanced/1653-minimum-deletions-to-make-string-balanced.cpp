class Solution {
public:
    typedef long long ll;
    int minimumDeletions(string s) 
    {
        ll na=0,nb=0;
        for(auto t: s)
        {
            if(t=='a')
                na++;
            else
                nb++;
        }
        ll nac=0,nbc=0;
        ll ans=INT_MAX;
        for(auto t: s)
        {
            if(t=='a')
            {
               ans=min(ans,nbc+na-nac-1);
               ans=min(ans,nbc+na-nac);
            }
            else
            {
                ans=min(ans,nbc+na-nac);
                ans=min(ans,nbc+1+na-nac);
            }
            if(t=='a')
                nac++;
            else
                nbc++;
        }
        return ans;
    }
};