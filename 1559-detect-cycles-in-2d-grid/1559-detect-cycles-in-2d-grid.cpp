typedef long long ll;
ll parent[2000001];
ll siz[2000001];
ll dx[]={0,0,1,-1};
ll dy[]={1,-1,0,0};
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
    bool containsCycle(vector<vector<char>>& g)
    {
        ll ct=1;
        map<pair<ll,ll>,ll> mp;
        for(ll i=0;i<g.size();i++)
        {
           for(ll j=0;j<g[0].size();j++)
           {
               mp[{i,j}]=ct++;
           }
        }
        set<pair<ll,ll>> st;
        for(ll i=0;i<g.size();i++)
        {
            for(ll j=0;j<g[0].size();j++)
            {
                for(ll idx=0;idx<4;idx++)
                {
                    ll nx=i+dx[idx];
                    ll ny=j+dy[idx];
                    if(nx<0 || ny<0 || nx>=g.size() || ny>=g[0].size())
                        continue;
                    else if(g[i][j]==g[nx][ny])
                    {
                        ll a=mp[{i,j}];
                        ll b=mp[{nx,ny}];
                        if(a>b)
                            swap(a,b);
                        st.insert({a,b});
                    }
                    
                }
            }
        }
        for(ll i=1;i<ct;i++)
            make(i);
        for(auto t: st)
        {
            pair<ll,ll> p=t;
            if(find(t.first)==find(t.second))
                return true;
            Union(t.first,t.second);
        }
        return false;
    }
};