class Solution {
public:
    typedef long long ll;
    unordered_map<string,ll> mp;
    bool f(ll i,ll cc,string& s)
    {
        if(i==s.length() && cc>=2)
            return true;
        if(i==s.length())
            return false;
        string x="";
        for(ll j=i;j<s.length();j++)
        {
            x+=s[j];
            if(mp.find(x)!=mp.end())
            {
                if(f(j+1,cc+1,s))
                    return true;
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
    {   vector<string> ans;
        for(auto t:words)
            mp[t]++;
        for(auto t: words)
        {
            if(f(0,0,t))
            {
                ans.push_back(t);
            }
        }
      return ans;
    }
};