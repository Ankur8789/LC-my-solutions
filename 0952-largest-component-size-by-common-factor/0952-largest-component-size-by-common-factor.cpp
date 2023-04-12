typedef long long ll;
ll parent[2000001];
ll siz[2000001];
ll pres[2000001];
void make(ll v)
{
    parent[v] = v;
    siz[v] = 1;
}
ll find(ll v)
{
    if (parent[v] == v)
        return v;
    else 
        return parent[v] = find(parent[v]);
}
void Union(ll a, ll b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    { 
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}
class Solution {
public:
    unordered_map<int,vector<int>> mp;
    int largestComponentSize(vector<int>& nums) 
    {
        set<ll> st;
        ll n=-1;
        for(ll i=1;i<=100001;i++)
            make(i);
        for(ll i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
            n=max(n,1LL*nums[i]);
        }
        for(ll i=2;i<=n;i++)
        {   ll last=INT_MIN,f=-1;
            for(ll j=i;j<=n;j+=i)
            {
                if(st.find(j)!=st.end())
                {
                    if(last==INT_MIN)
                    {
                        last=j;
                    }
                    else
                        Union(j,last);
                }
            }
        }
        ll cc=1;
        for(auto t: nums)
        {
            cc=max(cc,siz[t]);
        }
        return cc;
    }
};