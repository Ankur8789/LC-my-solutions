class Solution {
public:
    bool check(int mid,vector<int>& nums, int p)
    {
        int i=0,cc=0;
        int n=nums.size();
        while(i<n)
        {
            if(i+1<n && nums[i+1]-nums[i]<=mid)
            {
                cc+=1;
                i+=2;
            }
            else
                i++;
        }
        return cc>=p;
    }
    int minimizeMax(vector<int>& nums, int p) 
    {
        sort(nums.begin(),nums.end());
        int l=0,r=1e9;
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(mid,nums,p))
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};