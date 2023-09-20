class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int i=0,j=0,sum=0,n=nums.size();
        int tot=0;
        int res=1e9;
        for(auto t: nums)
            tot+=t;
        if(tot<x)
            return -1;
        if(tot==x)
            return n;
        while(j<n)
        {
            sum+=nums[j];
            while(sum>tot-x)
            {
                sum-=nums[i];
                i++;
            }
            if(sum==tot-x)
                res=min(res,n-(j-i+1));
            j++;  
        }
        return res=res==1e9?-1:res;
    }
       
};