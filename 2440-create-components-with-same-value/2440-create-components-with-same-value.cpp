class Solution {
public:
    typedef long long ll;
    vector<ll> adj[100001];
    ll cnt;
    ll f(ll x,ll par,vector<int>& nums,ll d)
    {
        ll sum=0;
        for(auto t: adj[x])
        {  
            if(t==par)
            continue;
            ll temp=f(t,x,nums,d);
            if(temp==-1)
            return -1;
            sum+=temp;
        }
        sum+=nums[x];
        if(sum==d)
        {
            ++cnt;
            return 0;
        }
        if(sum>d)
            return -1;
        
        return sum;
    }
    int componentValue(vector<int>& nums, vector<vector<int>>& eg) 
    {
        for(auto t:eg)
        {
            adj[t[0]].push_back(t[1]);
            adj[t[1]].push_back(t[0]);
        }
        ll sum=0;
        cnt=0;
        for(auto t: nums)sum+=t;
        for(int i=1;i<=(sum/2);i++)
        {
            if(sum%i==0)
            {
               ll x=f(0,-1,nums,i);
                cout<<i<<" "<<cnt<<endl;
               if(x!=-1)
               {
                  if(cnt==sum/i)
                      return cnt-1;
               }
                
            }
            cnt=0;
        }
        return 0;
        
    }
};