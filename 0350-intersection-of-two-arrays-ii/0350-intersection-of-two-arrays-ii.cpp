class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> fr1(1001),fr2(1001);
        for(auto x: nums1)
            fr1[x]++;
        for(auto x: nums2)
            fr2[x]++;
        vector<int> ans;
        for(int i=0;i<=1000;i++)
        {
            if(fr1[i] && fr2[i])
            {
                int sz=min(fr1[i],fr2[i]);
                while(sz--)
                    ans.push_back(i);
            }
        }
        return ans;
    }
};