class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) 
    {
        map<int,int> mp1,mp2;
        for(auto t: nums1)
            mp1[t]++;
        for(auto t: nums2)
            mp2[t]++;
        for(auto t: mp2)
        {
            if(mp1[t.first]>0)
                return t.first;
        }
        return -1;
        
    }
};