class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains)
    {
        int n=rains.size();
        map<int,int> mp;
        set<int> wet;
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            if(rains[i]==0)
            {
                wet.insert(i);
            }
            else
            {
                if(mp.find(rains[i])==mp.end())
                    mp[rains[i]]=i;
                else
                {
                    int val=mp[rains[i]];
                    auto it=wet.lower_bound(val);
                    if(it==wet.end())
                        return {};
                    ans[*it]=rains[i];
                    wet.erase(it);
                    mp[rains[i]]=i;
                   
                }
                 ans[i]=-1;
            }
        }
        for(auto &t: ans)
            t=(t==0)?1:t;
        return ans;
    }
};