class Solution {
public:
    int countKDifference(vector<int>& nums, int k) 
    {
        unordered_map<int,int> m;
        for(auto t:nums)
            m[t]++;
        int cnt=0;
         for(int i=0;i<nums.size();i++)
         {
             if(m[nums[i]+k]>0)
                 cnt+=m[nums[i]+k];
             if(m[nums[i]-k]>0)
                 cnt+=m[nums[i]-k];
            // m[nums[i]]++;
                 
         }
        return cnt/2;
    }
};