class Solution {
public:
    static bool cmp(pair<int,int>& a,pair<int,int>& b)
    {
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<pair<int,int>> v;
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        for(auto t=m.begin();t!=m.end();t++)
            v.push_back({t->first,t->second});
        sort(v.begin(),v.end(),cmp);
        vector<int> ans;
        int kn=0;
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(v[i].first);
            kn++;
            if(kn==k)
                break;
            
        }
        return ans;
        
    }
};