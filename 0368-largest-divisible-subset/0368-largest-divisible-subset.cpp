#define ws << ' '
#define el << '\n'
#define nl cout<<'\n';
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int,int>
#define getbit(x,y) (((x)>>(y))&1)
#define turnonandupdate(x,y) x=((x)|(1<<y))
#define turnoffandupdate(x,y) x=(x & ~(1 << (y)))
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) (int)(x).size()
#define setbits(x) __builtin_popcount(x)
#define sortall(x) sort(all(x))
#define sortallr(x) sort(rall(x))

// #define debug(...) 42
const int mod = 1e9+7;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        sortall(nums);
        int n=nums.size();
        vector<pii> dp(n);
        int mx=0,ind;
        for (int i = 0; i < n; i++)
        {
            dp[i]={1,-1};
            for (int j = i - 1; j >= 0; j--)
            {
                if(nums[i]%nums[j]==0) {
                    if(dp[j].first+1>dp[i].first) {
                        dp[i]={dp[j].first+1,j};
                    }
                }
            }
            if(dp[i].first>mx) 
            {
                mx=dp[i].first;
                ind=i;
            }
        }
        vector<int> ans;
        int curr=ind;
        while (curr!=-1)
        {
            ans.push_back(nums[curr]);
            curr=dp[curr].second;
        }
        reverse(all(ans));
        return ans;
    }
};