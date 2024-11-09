class Solution {
public:
    typedef long long ll;
    long long minEnd(int n, int x) {
       ll val = x;
       n--;
       x = ll(x) , n = ll(n);
       for(ll i=0;i<64;i++){
           if(n == 0)
               break;
           if((val>>i)&1LL) continue;
           val |= (n&1LL)<<i;
           n = n >> 1;
       }
       return val;
    }
};