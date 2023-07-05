class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
       int res=0;
       int i=0,j=0,n=nums.size();
       int zr=0;
       while(j<n)
       {
           if(nums[j]==0)
               zr++;
           while(zr>1)
           {
               if(nums[i]==0)
                   zr--;
               i++;
           }
          res=max(res,j-i);
           j++;
       }
        return res;
    }
};