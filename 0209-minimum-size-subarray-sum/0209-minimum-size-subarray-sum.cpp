class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
       int i=0,j=0,n=nums.size();
       int sum=0,res=1e9;
       while(j<n)
       {
           sum+=nums[j];
           while(sum-nums[i]>=target)
           {
               sum-=nums[i];
               i++;
           }
           // cout<<res<<endl;
           if(sum>=target)
               res=min(res,j-i+1);
           j++;
               
       }
        if(res==1e9)
            return 0;
        return res;
    }
};