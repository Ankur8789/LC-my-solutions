class Solution {
public:
    typedef long long ll;
    int countVowelSubstrings(string s) 
    {
        ll cnt=0;
        
        for(ll i=0;i<s.length();i++)
        {  ll ax=0,ex=0,ix=0,ox=0,ux=0;
            for(ll j=i;j<s.length();j++)
            {
                if(s[j]=='a')
                    ax++;
                if(s[j]=='e')
                    ex++;
                if(s[j]=='i')
                    ix++;
                if(s[j]=='o')
                    ox++;
                if(s[j]=='u')
                    ux++;
                if(j-i+1==ax+ex+ix+ox+ux && (ax>0 && ex>0 && ix>0 && ox>0 && ux>0))
                    ++cnt;
            }
        }
        return cnt;   
    }
};