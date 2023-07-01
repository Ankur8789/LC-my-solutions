class Solution {
public:
    typedef long long ll;
    ll ans=1e18;
    void f(int i,vector<int>& ck, int k,vector<ll>& freq)
    {
        if(i==ck.size())
        { 
           ll temp=-1e18;
           for(auto t:freq)
            temp=max(temp,1LL*t);
            // cout<<temp<<endl;
            ans=min(ans,temp);
            return ;
        }
        for(int idx=0;idx<k;idx++)
        {
            freq[idx]+=ck[i];
            f(i+1,ck,k,freq);
            freq[idx]-=ck[i];
        }
        
    }
    int distributeCookies(vector<int>& cookies, int k) 
    {
        vector<ll> freq(k);
        f(0,cookies,k,freq);
        return ans;
    }
};