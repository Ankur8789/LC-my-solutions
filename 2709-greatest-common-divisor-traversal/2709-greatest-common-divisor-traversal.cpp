#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
ll mxele;
ll parent[100001];
ll siz[100001];

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

    
    bool gcdSort(vector<int>& nums) 
    {
        mxele=*max_element(begin(nums),end(nums));
        vector<ll> vis(mxele+1);
        ll cc=0;
        for(auto t: nums)
        {
            if(vis[t]==0)
                cc++;
            vis[t]++;
        }
        for(ll i=1;i<mxele+1;i++)
        {
            if(vis[i])
                make(i);
        }
        for(ll i=2;i<mxele+1;i++)
        {
            ll last=-1;
            for(ll j=i;j<mxele+1;j+=i)
            {
               if(vis[j]>0)
               {
                   if(last==-1)
                       last=j;
                   else
                   {
                       Union(last,j);
                       last=j;
                   }
               }
            }
        }
        
        unordered_set<ll> st;
        for(ll i=0;i<nums.size();i++)
        {
           st.insert(find(nums[i]));
        }
        return st.size()==1;
    }

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums)
    {
        fastio();
        if(nums.size()==1)
            return true;
        for(auto t: nums)
        {
            if(t==1)
                return false;
        }
        return gcdSort(nums);
    }
};