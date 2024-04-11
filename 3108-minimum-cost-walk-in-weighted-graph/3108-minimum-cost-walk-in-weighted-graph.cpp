typedef long long ll;
ll parent[200001];
ll siz[200001];
vector<ll> val;
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
        val[a] &= val[b];
    }
}

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) 
    {
        val.clear();
        val.resize(n,(1<<20)-1);
        for(ll i=0;i<n;i++)make(i);
        vector<int> ans;
        for(auto t: edges)
        {
            ll u = t[0];
            ll v = t[1];
            ll wt = t[2];
            Union(u,v);
            val[find(u)]&=wt;
            cout<<val[find(u)]<<endl;
        }
        for(auto t: query)
        {
            ll u = t[0];
            ll v = t[1];
            ll x = find(u);
            ll y = find(v);
            if(x != y)
                ans.push_back(-1);
            else
                ans.push_back(val[x]);
        
        }
        return ans;
    }
};