typedef long long ll;
ll parent1[200001];
ll siz1[200001];
void make1(ll v)
{
    parent1[v] = v;
    siz1[v] = 1;
}
ll find1(ll v)
{
    if (parent1[v] == v)
        return v;
    else // path compresssion
        return parent1[v] = find1(parent1[v]);
}
void Union1(ll a, ll b)
{
    a = find1(a);
    b = find1(b);
    if (a != b)
    { // union by size
        if (siz1[a] < siz1[b])
            swap(a, b);
        parent1[b] = a;
        siz1[a] += siz1[b];
    }
}
ll parent2[200001];
ll siz2[200001];
void make2(ll v)
{
    parent2[v] = v;
    siz2[v] = 1;
}
ll find2(ll v)
{
    if (parent2[v] == v)
        return v;
    else // path compresssion
        return parent2[v] = find2(parent2[v]);
}
void Union2(ll a, ll b)
{
    a = find2(a);
    b = find2(b);
    if (a != b)
    { // union by size
        if (siz2[a] < siz2[b])
            swap(a, b);
        parent2[b] = a;
        siz2[a] += siz2[b];
    }
}
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) 
    {
        for(int i=0;i<n;i++)
            make1(i+1),make2(i+1);
        int cnt=0;
        sort(begin(edges),end(edges));
        reverse(begin(edges),end(edges));
        int rem=0;
        for(auto x: edges)
        {
            ll type=x[0];
            ll u=x[1];
            ll v=x[2];
            if(type==3)
            {
               if(find1(u)!=find1(v) || find2(u)!=find2(v))
               {
                   Union1(u,v);
                   Union2(u,v);
               }
               else
                   cnt++;
            }
            else
            {
               if(type==1)
               {
                  if(find1(u)!=find1(v))
                      Union1(u,v);
                  else
                      cnt++;
               }
               else
               {
                   if(find2(u)!=find2(v))
                       Union2(u,v);
                   else
                       cnt++;
               }
            }
        }
        if(siz1[find1(1)]==n && siz2[find2(1)]==n)
            return cnt;
        else
            return -1;
    }
};