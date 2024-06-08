class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k)
    {
       map<int,int> mp;
       int ps=0;
       for(int i=0;i<nums.size();i++)
       {
           int x=nums[i];
           ps+=x;
           ps%=k;
           if(ps==0 && i+1>=2)
               return 1;
           if(mp.find(ps)==mp.end())
               mp[ps]=i;
           else
           {
               if(i-mp[ps]>=2)
                   return 1;
           }
       }
        return 0;
    }
};