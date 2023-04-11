typedef long long ll;
ll parent[26];
ll siz[26];
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
    bool equationsPossible(vector<string>& eq) 
    {
        for(ll i=0;i<26;i++)
            make(i);
        for(auto t: eq)
        {
            ll x=t[0]-'a';
            ll y=t[3]-'a';
            if(t[1]=='!')
            {
               continue;
            }
            else
            {
                Union(x,y); 
            }
        }
        for(auto t: eq)
        {
            ll x=t[0]-'a';
            ll y=t[3]-'a';
            if(t[1]=='!')
            {
                if(find(x)==find(y))
                    return false;
            }
        }
        return true;
    }
};