typedef long long ll;
ll parent[200001];
ll siz[200001];
void make(ll v)
{
    parent[v] = v;
    siz[v] = 1;
}
ll find(ll v)
{
    if (parent[v] == v)
        return v;
    else // path compresssion
        return parent[v] = find(parent[v]);
}
void Union(ll a, ll b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    { // union by size
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}
unordered_map<ll,vector<ll>> mp;
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        ll n=s.length();
        for(ll i=0;i<n;i++)
            make(i);
        for(auto t: pairs)
        {
            Union(t[0],t[1]);
        }
        unordered_map<ll,multiset<char>> ms;
        for(ll i=0;i<n;i++)
        {
            ll a=find(i);
            ms[a].insert(s[i]);
        }
        string ans;
        ans.resize(n);
        for(ll i=0;i<n;i++)
        {
           ll a=parent[i];
            ans[i]=*ms[a].begin();
            ms[a].erase(ms[a].begin());
        }
        return ans;
    }
};