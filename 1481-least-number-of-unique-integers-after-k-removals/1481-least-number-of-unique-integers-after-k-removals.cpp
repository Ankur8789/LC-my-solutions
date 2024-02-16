class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) 
    {
        map<int,int> mp;
        for(auto t: arr)
            mp[t]+=1;
        vector<pair<int,int>> vp;
        for(auto t: mp)
            vp.push_back({t.second,t.first});
        sort(begin(vp),end(vp));
        reverse(begin(vp),end(vp));
        int curr=k;
        while(curr>0 && vp.size())
        {
            int val=vp.back().first;
            if(curr>=val)
            {
                curr-=val;
                vp.pop_back();
            }
            else
            {
                curr=0;
                break;
            }
        }
        return vp.size();
        
    }
};