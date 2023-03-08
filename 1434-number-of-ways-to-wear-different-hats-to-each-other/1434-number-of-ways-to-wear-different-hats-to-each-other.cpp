class Solution
{
public:
    //just change th phase of  dp ie from hats to people
    const int mod = 1e9 + 7;
    int dp[41][10001];
    int ppc(int n)
    {
        int c = 0;
        for (; n; ++c)
            n &= n - 1;
        return c;
    }
    int f(int i, int msk, vector<vector<int>> &vp,int x)
    {  //cout<<msk<<endl;
        if(ppc(msk)==x)
            return 1;
        if(i==vp.size())
            return 0;
        if(dp[i][msk]!=-1)
            return dp[i][msk];
       // int tmpmsk=msk;
        int ans=0;
        ans+=f(i+1,msk,vp,x);
        ans%=mod;
       for (int p:vp[i])
       {
            if ((msk & (1<<p))==0) 
            {
                ans+=f(i+1,msk | (1<<p),vp,x);
                ans%=mod;
            }
        }
        return dp[i][msk]=ans;
    }
    int numberWays(vector<vector<int>> &hats)
    {
        map<int, vector<int>> mp;
        int x = hats.size();
        for (int i = 0; i < x; i++)
        {
            vector<int> v = hats[i];
            for (int j = 0; j< v.size(); j++)
                mp[v[j]].push_back(i);
        }
        vector<vector<int>> vp;
        for (auto t : mp)
            vp.push_back(t.second);
        // for(auto t: vp)
        // {
        //     for(auto x: t)
        //         cout<<x<<" ";
        //     cout<<endl;
        // }
        memset(dp,-1,sizeof(dp));
        int ans = f(0,0,vp,x);
        ans %= mod;
        return ans;
    }
};