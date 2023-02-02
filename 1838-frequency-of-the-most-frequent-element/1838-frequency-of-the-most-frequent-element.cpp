class Solution {
public:
    //very good question
    typedef long long ll;
    int maxFrequency(vector<int>& nums, int k) 
    {
       sort(nums.begin(),nums.end());
        ll i=0,j=0,n=nums.size();
        ll sum=0;
        ll res=INT_MIN;
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