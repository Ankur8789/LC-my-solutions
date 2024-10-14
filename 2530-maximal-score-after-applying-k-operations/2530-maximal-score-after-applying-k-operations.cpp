class Solution {
public:
    typedef long long ll;
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<ll> pq;
        for(auto x : nums)
            pq.push(x);
        ll sum = 0;
        while(k--){
            auto u = pq.top();
            sum += u;
            pq.pop();
            ll val = (u + 2)/3;
            pq.push(val);
        }
        return sum;
    }
};