class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        //binary search
        if(nums.size()==1)
            return nums[0];
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            int prev,next;
            if(mid==0)
                prev=nums[mid]-1;
            else
                prev=nums[mid-1];
            if(mid==n-1)
                next=nums[mid]+1;
            else
                next=nums[mid+1];
            if(nums[mid]!=prev && nums[mid]!=next)
                return nums[mid];
            if(mid%2==0)
            {
                if(nums[mid]==prev)
                    r=mid-1;
                else
                    l=mid+1;
                    
            }
            else
            {
                if(nums[mid]==next)
                    r=mid-1;
                else
                    l=mid+1;
            }
                
        }
        return -1;
    }
};