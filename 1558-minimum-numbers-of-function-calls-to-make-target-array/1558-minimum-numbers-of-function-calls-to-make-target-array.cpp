class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int mx=INT_MIN;
        int on=0;
        for(int i=0;i<nums.size();i++)
        {
            int u=nums[i];
            int cnt=0;
            while(u>0)
            {
                if(u&1)
                {
                    u--;
                    on++;
                }
                else
                {
                    u/=2;
                    cnt++;
                }
            }
            mx=max(mx,cnt);
        }
       return mx+on;
    }
};