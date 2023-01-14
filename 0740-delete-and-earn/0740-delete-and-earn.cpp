class Solution {
public:
    int t[100001][2];
    int f(int i,int sex,vector<pair<int,int>>& v)
    {
        if(i==v.size())
            return 0;
        if(t[i][sex]!=-1)
            return t[i][sex];
        if(sex)
            return t[i][sex]=max(v[i].first*v[i].second+f(i+1,0,v),f(i+1,1,v));
        else
        {
            if(v[i].first==v[i-1].first+1)
                return t[i][sex]=f(i+1,1,v);
            else
                return t[i][sex]=max(v[i].first*v[i].second+f(i+1,0,v),f(i+1,1,v));
        }
    }
    int deleteAndEarn(vector<int>& nums)
    {
        map<int,int> mp;
        for(auto t: nums)
            mp[t]++;
        memset(t,-1,sizeof(t));
        vector<pair<int,int>> v;
        for(auto t: mp)
         v.push_back({t.first,t.second});
        int ans=f(0,1,v);
        return ans;
    }
};