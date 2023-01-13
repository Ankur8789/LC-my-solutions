class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        int i=0,j=0,n=nums.size();
        int cnt=0,pr=1;
        if(k==0)
            return 0;
        while(j<n)
        {
            pr*=nums[j];
            while(pr>=k)
            {
                pr/=nums[i];
                i++;
            }
            cnt+=(j-i+1);
            j++;
        }    
        if(cnt<0)
            cnt=0;
        return cnt;
    }
};