typedef long long ll;
ll ppc(ll n)
{
    ll c = 0;
    for (; n; ++c)
        n &= n - 1;
    return c;
}
ll k;
class Solution
{
public:
    vector<ll> mask;
    unordered_map<string, ll> mp;
    map<string, ll> dp;
    ll f(int i, unordered_set<string> &st, vector<vector<string>> &people,ll msk)
    {
        if(i==mask.size())
        {
            if(ppc(msk)==st.size())
                return 0;
            else
                return INT_MAX;
        }
        string val=to_string(i)+" "+to_string(msk);
        if(dp.count(val))
            return dp[val];
        ll a=f(i+1,st,people,msk);
        ll b=f(i+1,st,people,msk|mask[i]);
        ll ans=0;
        if(ppc(a)>ppc(b))
            ans=b|(1LL<<i);
        else
            ans=a;
        return dp[val]=ans;
    }
    vector<int> smallestSufficientTeam(vector<string> &req, vector<vector<string>> &people)
    {
        unordered_set<string> st;
        
        for (int i = 0; i < req.size(); i++)
            mp[req[i]] = i;
        for (auto t : req)
            st.insert(t);
        vector<ll> temp;
        mask.resize(people.size(), 0);
        for (int i = 0; i < people.size(); i++)
        {
            vector<string> &temp = people[i];
            int t = 0;
            for (string &skill : temp)
            {
                t |= 1 << mp[skill];
            }
            mask[i] = t;
        }
        k = (1 << req.size()) - 1;
        dp.clear();
        ll val = f(0, st, people, 0);
        ll index=0;
        vector<int> ans;
         while (val > 0) 
         {
            ll pick = val & 1;
            if (pick == 1) 
            {
                ans.push_back(index);
            }
            index++;
            val >>= 1;
        }
        return ans;
    }
};