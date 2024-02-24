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
void Reset(ll a)
{
    parent[a]=a;
}
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meet, int firstPerson) 
    {
        for(ll i=0;i<n;i++)make(i);
       Union(0,firstPerson);
       map<ll,vector<vector<ll>>> mp;
       for(auto t: meet)
           mp[t[2]].push_back({t[0],t[1]});
       vector<int> ans;
       for(auto t: mp)
       {
           // cout<<t.first<<"->"<<endl;
           
           vector<vector<ll>> logs=t.second;
           for(auto t: logs)
           {
               Union(t[0],t[1]);
           }
           for(auto t:logs)
           {
               if(find(0)!=find(t[0]))
               {
                   Reset(t[0]);
                   Reset(t[1]);
               }
           }
       }
       for(int i=0;i<n;i++)
       {
           if(find(0)==find(i))
               ans.push_back(i);
       }
        return ans;
       
    }
};