class Solution {
public:
    int reductionOperations(vector<int>& nums) 
    {
        map<int,int> mp;
        for(auto t: nums)
            mp[t]++;
        vector<int> v;
        for(auto t: mp)
            v.push_back(t.first);
        if(v.size()==1)
            return 0;
        int cnt=0;
        reverse(begin(v),end(v));
        for(int i=0;i<v.size()-1;i++)
        {
            cnt+=mp[v[i]];
            // mp[v[i]]=0;
            mp[v[i+1]]+=mp[v[i]];
        }
        return cnt;
        
    }
};