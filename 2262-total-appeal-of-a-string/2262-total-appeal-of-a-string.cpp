class Solution {
public:
    typedef long long ll;
    long long appealSum(string s) 
    {
        ll cc=0;
        unordered_map<char,ll> mp;
        ll n=s.size();
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])==mp.end())
                cc+=(i+1)*(n-i);
            else
                cc+=(i-mp[s[i]])*(n-i);
            mp[s[i]]=i;
        }
        return cc;
    }
};