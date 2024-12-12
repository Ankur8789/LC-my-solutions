class Solution {
public:
    typedef long long ll;
    long long pickGifts(vector<int>& gifts, int k) 
    {
        ll ans=0;
        priority_queue<ll> pq;
        for(auto t: gifts)pq.push(t);
        while(k--){
            ll x=pq.top();
            pq.pop();
            ll y=sqrt(x);
            pq.push(y);
        }
        while(pq.size()>0){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};