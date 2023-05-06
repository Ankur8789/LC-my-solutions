typedef long long ll;
ll mpw(int base, int exp, int M)
{
    // O(LOGEXP) TIME
    if (exp == 0)
        return 1;
    ll res = mpw(base, exp / 2, M);
    if (exp % 2 == 1)
        return (((res * res) % M) * base) % M;
    else
        return (res * res) % M;
}
class Solution {
public:
    const int mod=1e9+7;
    int numSubseq(vector<int>& nums, int target) 
    {
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int val=nums[i];
            int l=i,r=nums.size()-1,ix=-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(nums[mid]<=target-val)
                {
                    ix=mid;
                    l=mid+1;
                }
                else
                    r=mid-1;
            }
            if(ix==-1)
                continue;
            else
            {   
                cout<<ix<<" ";
                ans+=mpw(2,ix-i,mod);
                ans%=mod;
            }
        }
        return ans;
    }
};