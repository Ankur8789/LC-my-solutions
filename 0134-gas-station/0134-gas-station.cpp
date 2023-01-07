class Solution {
public:
    static bool cmp(pair<int,int>& a,pair<int,int>& b)
    {
        if(a.first-a.second==b.first-b.second)
            return a.second<b.second;
        else
            return a.first-a.second>b.first-b.second;
            
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        vector<pair<int,int>> v;
        for(int i=0;i<gas.size();i++)
            v.push_back({gas[i],cost[i]});
        int sx=0;
        for(auto it: v)
            sx+=(it.first-it.second);
        if(sx<0)
            return -1;
        sx=0;
        int idx=0;
        for(int i=0;i<gas.size();i++)
        {   sx+=v[i].first-v[i].second;
            if(sx<0)
            {
                sx=0;
                idx=i+1;
            }
            
                
         }
        return idx;
    }
};