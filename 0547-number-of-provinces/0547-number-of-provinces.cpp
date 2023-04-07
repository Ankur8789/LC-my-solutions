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
    int findCircleNum(vector<vector<int>>& ic) 
    {
        for(ll i=1;i<=ic.size();i++)
            make(i);
        for(ll i=0;i<ic.size();i++)
        {
            for(ll j=0;j<ic[0].size();j++)
            {
                if(i==j)
                    continue;
                if(ic[i][j]==1)
                    Union(i+1,j+1);
            }
        }
        ll cc=0;
        for(ll i=1;i<=ic.size();i++)
        {
            if(find(i)==i)
                cc++;
        }
        return cc;
    }
};