class Solution {
public:
    int maximumXOR(vector<int>& nums) 
    {
        int ans=0;
        for(auto t: nums)ans^=t;
        vector<int> msk(32);
        for(int i=0;i<nums.size();i++)
        {
            int v=nums[i];
            for(int j=0;j<32;j++)
            {
                if(((v>>j)&1) ==1)
                    msk[j]++;
            }
        }
        
        for(int i=0;i<32;i++)
        {
            if(msk[i]>=1)
            {
              ans|=(1<<i);
            }
        }
        return ans;
    }
};