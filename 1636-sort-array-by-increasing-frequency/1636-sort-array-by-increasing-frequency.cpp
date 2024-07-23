class Solution {
public:
    static bool cmp(pair<int,int>& a,pair<int,int>& b)
    {
        if(a.first==b.first)
            return a.second>b.second;
        else
            return a.first<b.first;
    }
    vector<int> frequencySort(vector<int>& nums) 
    {
        map<int,int> mp;
        for(auto x: nums)
            mp[x]+=1;
        vector<pair<int,int>> vp;
        for(auto t: mp)
            vp.push_back({t.second,t.first});
        sort(begin(vp),end(vp),cmp);
        vector<int> ans;
        for(auto x: vp)
        {
            int times=x.first;
            while(times--)
                ans.push_back(x.second);
        }
        return ans;
    }
};