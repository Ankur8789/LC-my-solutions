class Solution {
public:
    int calc(vector<int>& nums,int k)
    {
       int i=0,j=0,n=nums.size(),cnt=0,ans=0;
       while(j<n)
       {
           if(nums[j]&1)
               cnt++;
           while(cnt>k)
           {
               if(nums[i]&1)
                   cnt--;
               i++;
           }
           ans+=(j-i+1);
           j++;
       }
       return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
       return calc(nums,k)-calc(nums,k-1);
    }
};