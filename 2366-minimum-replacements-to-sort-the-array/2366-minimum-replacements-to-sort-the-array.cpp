class Solution {
public:
    typedef long long ll;
    long long minimumReplacement(vector<int>& nums) 
    {
        ll cc=0;
        ll n=nums.size();
        for(ll i=n-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
                continue;
            else
            {
                if(nums[i-1]%nums[i]==0)
                {
                    ll k=nums[i-1]/nums[i];
                    cc+=k-1;
                    nums[i-1]=nums[i ];
                }
                else
                {
                   ll k=nums[i-1]/nums[i];
                   ll rem=nums[i-1]/nums[i]+1;
                   cc+=k;
                   nums[i-1]/=rem;
                }
            }
        }
        return cc;
    }
};