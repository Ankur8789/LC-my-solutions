class Solution {
public:
    typedef long long ll;
    long long minimumSteps(string s) 
    {
       vector<ll> ones;
       for(ll i=0;i<s.size();i++)
       {
           if(s[i]=='1')
               ones.push_back(i);
       }
       if(ones.size()==0)
           return 0;
       ll ans=0;
       sort(ones.begin(),ones.end());
        reverse(ones.begin(),ones.end());
       ll n=s.size();
       if(ones[0]!=n-1)
           ans+=(n-1-ones[0]);
       ll curr=n-2;
       for(ll i=1;i<ones.size();i++)
       {
           ans+=abs(curr-ones[i]);
           curr--;
       }
       return ans;
           
       
    }
};