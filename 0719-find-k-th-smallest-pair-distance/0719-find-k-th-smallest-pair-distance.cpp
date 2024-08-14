class Solution {
public:
    bool check(int mid,vector<int>& nums,int k){
        int i=0,j=0,n=nums.size();
        int ans=0;
        while(j<n){
            while(nums[j]-nums[i]>mid)
                i++;
            ans+=i;
            j++;
        }
        int total=n*(n-1)/2;
        ans=total-ans;
        return ans>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int l=0,r=1e9;
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,nums,k)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};