class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr)
    {
        map<int,int> mp;
        for(auto t: arr)mp[t]+=1;
        map<int,int> res;
        for(auto t: mp)
        {
            if(res[t.second]>0)
                return 0;
            res[t.second]++;
        }
        return 1;
    }
};