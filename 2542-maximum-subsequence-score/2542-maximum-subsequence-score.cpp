class Solution {
public:
    typedef long long ll;
    long long maxScore(vector<int>& a, vector<int>& b, int k)
    {
       
        vector<pair<ll,pair<ll,ll>>> arr;
        ll n=a.size();
        multiset<pair<ll,ll>> ms;
        for(int i=0;i<n;i++)
        {
            arr.push_back({b[i],{a[i],i}});
            ms.insert({a[i],i});
        }
        sort(arr.begin(),arr.end());
        
        ll sum=0;
        unordered_map<ll,ll> mp;
        for(ll i=0;i<k;i++)
        {
            sum+=ms.rbegin()->first;
            mp[ms.rbegin()->second]++;
            ms.erase(--ms.end());
        }
       
        ms.insert({-INT_MAX,-INT_MAX});
        ll ans=0;
        for(int i=0;i<n-k+1;i++)
        {
                
                ll curr=sum*arr[i].first;
                ans=max(ans,curr);
                    if(mp[arr[i].second.second]>0)
                    {
                        mp[arr[i].second.second]--;
                        
                        sum-=arr[i].second.first;
                        
                        sum+=ms.rbegin()->first;
                        mp[ms.rbegin()->second]++;
                        ms.erase(--ms.end());
                    }
                    else
                    {
                        if(ms.count({arr[i].second.first,arr[i].second.second}))                        
                        {
                            ms.erase(ms.find({arr[i].second.first,arr[i].second.second}));
                        }
                    }
        }
        return ans;
    }
};