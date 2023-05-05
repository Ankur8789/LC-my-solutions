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
    int countServers(vector<vector<int>>& grid) 
    {
        map<pair<ll,ll>,ll> mp;
        map<ll,vector<ll>> mpr,mpc;
        ll k=1;
        for(ll i=0;i<grid.size();i++)
        {
            for(ll j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                    mp[{i,j}]=k++;
            }
        }
        for(ll i=1;i<k;i++)
            make(i);
        for(ll i=0;i<grid.size();i++)
        {
            for(ll j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    mpr[i].push_back(mp[{i,j}]);
                    mpc[j].push_back(mp[{i,j}]);
                }
            }
        }
        for(auto t: mpr)
        {
            if(t.second.size()>1)
            {
                vector<ll> temp=t.second;
                for(ll i=0;i<temp.size()-1;i++)
                    Union(temp[i],temp[i+1]);
            }
        }
        for(auto t: mpc)
        {
            if(t.second.size()>1)
            {
                vector<ll> temp=t.second;
                for(ll i=0;i<temp.size()-1;i++)
                    Union(temp[i],temp[i+1]);
            }
        }
        ll ans=0;
        for(ll i=1;i<k;i++)
        {
            if(parent[i]==i)
            {
                if(siz[i]>1)
                    ans+=siz[i];
            }
        }
        return ans;
        
    }
};