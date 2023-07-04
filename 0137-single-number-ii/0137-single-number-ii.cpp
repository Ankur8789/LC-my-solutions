class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        vector<int> msk(32);
        for(auto t: nums)
        {
            int val=t;
            for(int i=0;i<32;i++)
            {
                if((val>>i)&1)
                    msk[i]++;
            }
        }
        int ans=0;
        for(int i=0;i<32;i++)
        {
            if(msk[i]%3!=0)
                ans|=(1<<i);
        }
        return ans;
    }
};