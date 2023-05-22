class Solution
{
public:
    typedef long long ll;
    const ll mod = 1e9 + 7;
    ll mpw(ll base, ll exp, ll M)
    {
        // O(LOGEXP) TIME
        if (exp == 0)
            return 1;
        ll res = mpw(base, exp / 2, M);
        if (exp % 2 == 1)
            return (((res * res) % M) * base) % M;
        else
            return (res * res) % M;
    }
    unordered_map<int, vector<int>> adj;
    ll F[1000001];
    ll num;
    void ix()
    {
        F[0] = F[1] = 1;
        for (ll i = 2; i <= 1000000; i++)
            F[i] = (F[i - 1] * 1LL * i) % mod;
    }
    ll dfs(ll x)
    {
        if(adj[x].size()==0)
            return 1;
        ll cnt=1;
        for(auto t: adj[x])
            cnt+=dfs(t);
        // cout<<x<<" "<<cnt<<endl;
        ll val=mpw(cnt,mod-2,mod);
        num*=val;
        num%=mod;
        // cout<<num<<endl;
        return cnt;
    }
    int waysToBuildRooms(vector<int> &pr)
    {
        ix();
        ll n = pr.size();
        vector<int> ideg(n);
        for (int i = 0; i < n; i++)
        {
            if (pr[i] == -1)
                continue;
            adj[pr[i]].push_back(i);
            // ideg[pr[i]]++;
        }
        // for(auto t: adj)
        // {
        //     cout<<t.first<<"-> ";
        //     for(auto x: t.second)
        //         cout<<x<<" ";
        //     cout<<endl;
        // }
        num = F[n] % mod;
        dfs(0);
        return num;
    }
};