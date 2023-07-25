class Solution {
public:
    int peakIndexInMountainArray(vector<int>& v) 
    {
        int n=v.size();
        int l=1,r=n-2;
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(v[mid]>v[mid-1] && v[mid]>v[mid+1])
            {
                ans=mid;
                break;
            }
            else if(v[mid]>v[mid-1] && v[mid+1]>v[mid])
             l=mid+1;
            else
             r=mid-1;
        }
        return ans;
    }
};