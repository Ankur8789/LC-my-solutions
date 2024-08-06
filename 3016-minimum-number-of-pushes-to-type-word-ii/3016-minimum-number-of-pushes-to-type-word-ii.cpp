class Solution {
public:
    typedef long long ll;
    int minimumPushes(string word) 
    {
        map<char,int> mp;
        for(auto t:word)
            mp[t]++;
        multiset<ll> ms;
        for(ll i=0;i<8;i++)
            ms.insert(0);
        cout<<ms.size()<<endl;
        vector<pair<ll,char>> vp;
        for(auto t: mp)
            vp.push_back({t.second,t.first});
        sort(vp.begin(),vp.end());
        reverse(vp.begin(),vp.end());
        ll ans=0;
        for(ll i=0;i<vp.size();i++)
        {
            auto x=*ms.begin();
            ll cnt=x;
            ms.erase(ms.begin());
            ans+=vp[i].first*(cnt+1);
            ms.insert(cnt+1);
        }
        return ans;
    }
};