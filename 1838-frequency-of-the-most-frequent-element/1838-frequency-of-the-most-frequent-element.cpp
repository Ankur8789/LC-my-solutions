class Solution {
public:
    typedef long long ll;
    int maxFrequency(vector<int>& nums, int k) 
    {
        sort(begin(nums),end(nums));
        int n=nums.size();
        ll res=0,sum=0;
        ll i=0,j=0;
        while(j<n)
        {
            sum+=nums[j];
            while(sum+k<(j-i+1)*nums[j])
            {
                sum-=nums[i];
                i++;
            }
            res=max(res,j-i+1);
            j++;
        }
        return res;
        
    }
};