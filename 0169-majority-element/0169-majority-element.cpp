class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        map<int,int> mp;
        for(auto t: nums)
            mp[t]+=1;
        for(auto t: mp)
        {
            if(t.second>(nums.size())/2)
                return t.first;
        }
        return -1;
    }
};