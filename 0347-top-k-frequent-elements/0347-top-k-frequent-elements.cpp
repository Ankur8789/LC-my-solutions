class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
       map<int,int> mp;
        for(auto t: nums)
            mp[t]++;
        vector<pair<int,int>> vp;
        for(auto t: mp)
            vp.push_back({t.second,t.first});
        sort(vp.begin(),vp.end());
        reverse(vp.begin(),vp.end());
        vector<int> ans;
        for(int i=0;i<k;i++)
            ans.push_back(vp[i].second);
        return ans;
            
    }
};