class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int zero=0;
        int prod=1;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)zero++;
            else
                prod*=nums[i];
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                if(zero==1)
                    ans.push_back(prod);
                else
                    ans.push_back(0);
            }
            else
            {
                if(zero>0)
                    ans.push_back(0);
                else
                    ans.push_back(prod/nums[i]);
            }
        }
        return ans;
    }
};