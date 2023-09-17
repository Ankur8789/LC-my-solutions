class Solution {
public:
    typedef long long ll;
    bool check(ll mid,int k,int budget,vector<vector<int>>& comp, vector<int>& stock, vector<int>& cost)
    {
        for(auto t: comp)
        {
            vector<ll> req(t.size());
            for(int i=0;i<t.size();i++)
            {
                req[i]=mid*t[i];
                // cout<<req[i]<<" ";
                req[i]=max(req[i]-stock[i],0*1LL);
            }
            // cout<<endl;
            // for(auto t: req)
            //     cout<<t<<" ";
            // cout<<endl;
            ll sum=0;
            for(int i=0;i<t.size();i++)
                sum+=1LL*req[i]*cost[i];
            if(sum<=budget)
                return 1;
        }
        return 0;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& comp, vector<int>& stock, vector<int>& cost) 
    {
        sort(comp.begin(),comp.end());
        ll l=0,r=1e10;
        ll ans=0;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(check(mid,k,budget,comp,stock,cost))
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        // cout<<check(2,k,budget,comp,stock,cost)<<endl;
        return ans;
        
    }
};