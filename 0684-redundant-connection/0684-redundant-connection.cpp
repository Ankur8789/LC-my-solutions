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
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& ed) 
    {
        for(ll i=1;i<=ed.size();i++)
          make(i);
        vector<int> ans;
        for(auto t: ed)
        {
           ll a=find(t[0]);
           ll b=find(t[1]);
           if(a==b)
           {
              return t;
           }
            Union(t[0],t[1]);
        }
        return {};
    }
};