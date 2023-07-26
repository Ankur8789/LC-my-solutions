class Solution {
public:
    unordered_map<int,int> index;
    unordered_map<int,int> reject;
    const int mod=1e9+7;
    int mx=901;
    int dp[1001][3001];
    vector<int> primes;
    int pf(int val)
    {
        int mask=0;
        for(int i=0;i<primes.size();i++)
        {
            int cc=0;
            while((val%primes[i])==0)
            {
                cc++;
                val/=primes[i];
            }
            if(cc>1)
                return -1;
            if(cc==1)
                mask|=(1<<i);
        }
        return mask;
    }
    int f(int i,int msk,vector<int>& nums)
    {
        if(i==nums.size())
            return 1;
        if(dp[i][msk]!=-1)
            return dp[i][msk];
        int ans=0;
        ans+=f(i+1,msk,nums);
        ans%=mod;
        int tmpmsk=pf(nums[i]);
        if(tmpmsk!=-1 && !(tmpmsk&msk))
        {
            ans+=f(i+1,(tmpmsk|msk),nums);
            ans%=mod;
        }
        return dp[i][msk]=ans;
        
    }
    int squareFreeSubsets(vector<int>& nums) 
    {
        // vector<bool> soe(91, 1);
        // for (int i = 2; i * i <= 91; i++)
        // {
        //     if (soe[i] == true)
        //     {
        //         for (int j = i * i; j <= 91; j += i)
        //             soe[j] = false;
        //     }
        // }
        primes.clear();
        // primes.push_back(1);
        // for(int i=2;i<=30;i++)
        // {
        //     if(soe[i]==true)
        //         primes.push_back(i);
        // }
         primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        memset(dp,-1,sizeof(dp));
        int ans=f(0,0,nums);
        // for(auto t: primes)
        //     cout<<t<<" ";
        ans-=1;
        ans+=mod;
        ans%=mod;
        return ans;
    }
};