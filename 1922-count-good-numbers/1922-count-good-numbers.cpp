typedef long long ll;
const ll mod=1e9+7;
ll mpw(ll base, ll exp, ll M)
{
    // O(LOGEXP) TIME
    if (exp == 0)
        return 1;
    ll res = mpw(base, exp / 2, M);
    if (exp % 2 == 1)
        return (((res * res) % M) * base) % M;
    else
        return (res * res) % M;
}
class Solution {
public:
    
    int countGoodNumbers(long long n) 
    {
        ll ans=1;
        ll od=0,ev=0;
        ev=n/2;
        if(n&1)
            od=ev+1;
        else
            od=ev;
        ans*=mpw(5,od,mod);
        ans%=mod;
        ans*=mpw(4,ev,mod);
        ans%=mod;
        return ans;
    }
};