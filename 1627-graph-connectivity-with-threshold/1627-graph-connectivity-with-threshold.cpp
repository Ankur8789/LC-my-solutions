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
    vector<bool> areConnected(int n, int thr, vector<vector<int>>& quer) 
    {
       for(ll i=1;i<=n;i++)make(i);
       // threshold se jada
       for(ll i=thr+1;i<=1e5;i++)
       {
           if(i>n)
               break;
           ll last=-1;
           for(ll j=i;j<1e5+1;j+=i)
           {
               if(j>n)
                   break;
               if(last==-1)
                   last=j;
               else
               {
                   Union(last,j);
               }
           }
       }
       vector<bool> ans;
       for(auto t: quer)
       {
           ll u=t[0];
           ll v=t[1];
           if(find(u)==find(v))
               ans.push_back(true);
           else
               ans.push_back(false);
       }
       return ans;
    }
};