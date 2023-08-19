class Solution {
public:
    typedef long long ll;
    long long makeSubKSumEqual(vector<int>& arr, int k)
    {
        ll ans=0;
        ll n=arr.size();
        vector<int> vis(n,0);
        for(ll i=0;i<k;i++)
        {
           if(vis[i]==0)
           {
               int j=i;
               vector<int> res;
               while(vis[j]==0)
               {
                   res.push_back(arr[j]);
                   vis[j]=1;
                   j+=k;
                   j%=n;
                   
               }
               sort(res.begin(),res.end());
               int sz=res.size();
               sz/=2;
               for(auto t: res)
                   ans+=abs(t-res[sz]);
           }
        }
        return ans;
    }
};