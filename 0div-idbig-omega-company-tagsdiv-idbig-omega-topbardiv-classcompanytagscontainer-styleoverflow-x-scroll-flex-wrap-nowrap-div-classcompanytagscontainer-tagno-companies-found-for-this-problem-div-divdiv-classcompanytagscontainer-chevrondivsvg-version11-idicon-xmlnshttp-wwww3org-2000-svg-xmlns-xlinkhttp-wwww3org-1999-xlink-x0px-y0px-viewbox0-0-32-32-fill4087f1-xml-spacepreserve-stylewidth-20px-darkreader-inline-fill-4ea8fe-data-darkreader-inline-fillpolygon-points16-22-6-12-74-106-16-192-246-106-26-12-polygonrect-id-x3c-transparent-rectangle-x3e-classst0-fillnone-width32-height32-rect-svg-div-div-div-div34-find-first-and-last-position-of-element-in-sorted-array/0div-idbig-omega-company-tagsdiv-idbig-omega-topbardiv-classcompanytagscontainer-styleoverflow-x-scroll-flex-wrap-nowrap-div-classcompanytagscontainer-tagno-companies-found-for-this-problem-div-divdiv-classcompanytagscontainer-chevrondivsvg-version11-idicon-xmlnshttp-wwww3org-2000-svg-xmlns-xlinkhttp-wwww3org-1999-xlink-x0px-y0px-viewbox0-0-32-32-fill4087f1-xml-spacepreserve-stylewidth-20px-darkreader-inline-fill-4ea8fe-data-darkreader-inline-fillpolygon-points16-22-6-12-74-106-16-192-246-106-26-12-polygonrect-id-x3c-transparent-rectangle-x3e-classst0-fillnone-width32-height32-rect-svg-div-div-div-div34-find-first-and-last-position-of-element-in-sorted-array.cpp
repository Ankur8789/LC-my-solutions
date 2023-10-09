class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int first;
        int l=0,r=nums.size()-1;
        bool ok=false;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]<=target)
            {
                if(nums[mid]==target)
                    ok=true;
                first=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        l=0,r=nums.size()-1;
        int last=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]>=target)
            {
                last=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        if(!ok)
            return {-1,-1};
        else
            return {last,first};
    }
};