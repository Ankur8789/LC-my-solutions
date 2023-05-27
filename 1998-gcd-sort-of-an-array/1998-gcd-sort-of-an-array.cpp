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
    // int vis[100001];
    // int cc;
    // unordered_map<int,vector<int>> adj;
    // void dfs(int x)
    // {
    //     vis[x]=1;
    //     cc++;
    //     for(auto t: adj[x])
    //     {
    //         if(vis[t]==0)
    //             dfs(t);
    //     }
    // }
    bool gcdSort(vector<int>& nums) 
    {
        unordered_map<int,int> mp;
        for(auto t: nums)
            mp[t]++;
        for(auto t: mp)
            make(t.first);
        for(int i=2;i<1e5+1;i++)
        {
            int last=-1;
            for(int j=i;j<=1e5+1;j+=i)
            {
               if(mp.find(j)!=mp.end())
               {
                   if(last==-1)
                       last=j;
                   else
                   {
                       Union(last,j);
                       // last=j;
                   }
               }
            }
        }
        
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        for(int i=0;i<nums.size();i++)
        {
            if(find(nums[i])!=find(temp[i]))
                return false;
        }
        return true;
    }
};