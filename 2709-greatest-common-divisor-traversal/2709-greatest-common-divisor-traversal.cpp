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
    bool canTraverseAllPairs(vector<int>& nums) 
    {
       if(nums.size()==1)
           return 1;
       int maxi=*max_element(begin(nums),end(nums));
       for(int i=0;i<nums.size();i++)
           make(nums[i]);
       unordered_map<ll,ll> ava;
       for(auto t: nums)
           ava[t]+=1;
       if(ava.find(1)!=ava.end())
           return 0;
       for(int i=2;i<maxi+1;i++)
       {
           int val=i;
           int last=-1;
           for(ll j=val;j<maxi+1;j+=val)
           {
               if(ava.find(j)!=ava.end())
               {
                  if(last==-1)
                      last=j;
                   else
                   Union(last,j);
               }
           }
       }
       for(auto t: nums)
       {
           cout<<find(t)<<endl;
           if(find(t)!=find(nums[0]))
               return 0;
       }
        return 1;
    }
};