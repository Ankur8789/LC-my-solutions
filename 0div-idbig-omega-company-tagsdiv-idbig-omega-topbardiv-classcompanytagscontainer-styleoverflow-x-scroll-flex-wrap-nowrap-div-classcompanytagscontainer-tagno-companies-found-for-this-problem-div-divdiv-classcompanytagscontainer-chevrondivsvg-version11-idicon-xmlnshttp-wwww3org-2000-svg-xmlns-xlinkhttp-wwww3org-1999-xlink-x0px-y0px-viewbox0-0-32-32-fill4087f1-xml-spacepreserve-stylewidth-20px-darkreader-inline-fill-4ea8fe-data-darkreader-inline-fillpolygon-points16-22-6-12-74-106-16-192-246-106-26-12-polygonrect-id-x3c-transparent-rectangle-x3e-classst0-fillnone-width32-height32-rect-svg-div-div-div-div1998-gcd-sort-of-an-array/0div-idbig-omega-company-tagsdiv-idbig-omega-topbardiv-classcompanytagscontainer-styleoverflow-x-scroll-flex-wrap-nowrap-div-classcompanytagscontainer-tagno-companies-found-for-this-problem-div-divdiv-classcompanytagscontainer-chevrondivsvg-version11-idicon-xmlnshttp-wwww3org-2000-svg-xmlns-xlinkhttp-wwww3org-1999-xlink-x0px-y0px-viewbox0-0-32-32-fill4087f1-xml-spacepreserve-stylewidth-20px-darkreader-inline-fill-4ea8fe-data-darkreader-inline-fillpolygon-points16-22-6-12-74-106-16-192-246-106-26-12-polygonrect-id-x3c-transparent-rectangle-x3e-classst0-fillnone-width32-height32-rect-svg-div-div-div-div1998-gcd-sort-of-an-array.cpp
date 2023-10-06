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
    bool gcdSort(vector<int>& nums) 
    {
        unordered_map<ll,ll> mp;
        for(auto t: nums)mp[t]++;
        for(auto t: mp)make(t.first);
        
        for(ll i=2;i<=1e5;i++)
        {
           ll last=-1;
           for(ll j=i;j<=1e5;j+=i)
           {
               if(mp.find(j)!=mp.end())
               {
                   if(last==-1)
                       last=j;
                   else
                       Union(last,j);
               }
           }
        }
        vector<int> res=nums;
        sort(res.begin(),res.end());
        for(ll i=0;i<nums.size();i++)
        {
            if(find(nums[i])!=find(res[i]))return false;
        }
        return true;
    }
};