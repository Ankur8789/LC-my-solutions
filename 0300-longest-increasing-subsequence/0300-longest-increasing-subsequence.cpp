class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> v;
        v.push_back(nums[0]);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>v.back())
                v.push_back(nums[i]);
            else
            {
                int l=0,r=v.size()-1;
                int ans=0;
                while(l<=r)
                {
                    int mid=(l+r)/2;
                    if(v[mid]>=nums[i])
                    {
                        ans=mid;
                        r=mid-1;
                    }
                    else
                        l=mid+1;
                }
                v[ans]=nums[i];
            }
        }
        return v.size();
    }
};