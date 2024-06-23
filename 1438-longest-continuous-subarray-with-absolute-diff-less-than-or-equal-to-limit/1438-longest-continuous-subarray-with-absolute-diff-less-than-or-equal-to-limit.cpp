class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) 
    {
       multiset<int> ms;
       int i=0,j=0,n=nums.size(),res=0;
       while(j<n)
       {
           ms.insert(nums[j]);
           while(*ms.rbegin()-*ms.begin()>limit)
           {
               ms.erase(ms.find(nums[i]));
               i++;
           }
           res=max(res,j-i+1);
           j++;
       }
       return res;
    }
};