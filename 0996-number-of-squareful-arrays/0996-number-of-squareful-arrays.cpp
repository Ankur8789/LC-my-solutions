class Solution {
public:
    int dp[5001][13];
    int ppc(int n)
    {
        int cc = 0;
        while(n)
            n = (n & (n-1)), cc++;
        return cc;
    }
    int f(int mask,vector<int>& nums,int before)
    {
       if(ppc(mask) == nums.size())
           return 1;
        auto & x = dp[mask][before];
        if(x != -1)
            return x;
        map<int , int > mp;
        int ans = 0;
        for(int i = 0;i < nums.size();i++)
        {
            if((mask>>i)&1)
                continue;
            if(mp.count(nums[i]))
                continue;
            int val = nums[i] + nums[before];
            mp[nums[i]] += 1;
            int sqr = sqrtl(val);
            if(sqr*sqr == val)
            {
                // cout<< sqr * sqr << " " << val <<endl;
                ans += f(mask | (1<<i) , nums , i);
            }
            
        }
        return x = ans;
    }
    int numSquarefulPerms(vector<int>& nums)
    {
        memset(dp , -1 , sizeof(dp));
        map<int , int > mp;
        int ans = 0;
        for(int i = 0;i < nums.size() ; i++)
        {
            if(mp.count(nums[i]))
                continue;
            mp[nums[i]] += 1;
            ans += f((1<<i) , nums , i);
            // cout<<(1<<i)<<endl;
        }
            
        return ans;
    }
};