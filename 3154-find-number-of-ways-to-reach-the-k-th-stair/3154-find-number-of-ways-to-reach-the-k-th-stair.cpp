#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> T;
typedef long long ll;
typedef long double ld;
template <class T>
using pbset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using pbmultiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define SORT(A) sort(A.begin(), A.end());
#define REVERSE(A) reverse(A.begin(), A.end());
#define ull unsigned ll
#define mmt(a, v) memset(a, v, sizeof(a));
#define srt(A, n) sort(A, A + n);
#define ln "\n"
#define sz(x) int((x).size())
#define dbg cout << "debug\n";
#define err(x, n) cout << fixed << setprecision(x) << n << " " << endl;
#define INF 2e18
#define rep(i, l, r) for (int i = l; i < r; ++i)
#define per(i, l, r) for (int i = l; i >= r; --i)
#define fi first
#define se second
#define pll pair<ll, ll>
#define mp make_pair
#define chmin(a, b) a = a < b ? a : b
#define chmax(a, b) a = a > b ? a : b
#define umap unordered_map
#define uset unordered_set
const double pi = 3.14159265358979323846;
const ll mod = 1e9 + 7;
const ll modx = 998244353;
typedef priority_queue<ll> pqmax;
typedef priority_queue<ll, vector<ll>, greater<ll>> pqmin;
// binary search on real number l=mid||r=mid
// Ordered set functions
// it=s.find_by_order(x) (for index)
// s.order_of_key(x)(no of elements smaller than x)

//*************GP HASH TABLE*********
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(pll x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^ splitmix64(x.second + FIXED_RANDOM);
    }
    size_t operator()(ll x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
typedef gp_hash_table<ll, ll, custom_hash> hashll;
typedef gp_hash_table<pll, ll, custom_hash> hashpll;
//**************bin exp************
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
ll pw(ll a, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n % 2)
        {
            res *= a;
            n--;
        }
        else
        {
            a *= a;
            n /= 2;
        }
    }
    return res;
}
//**********ncr**************
ll F[1000001];
void ix()
{
    F[0] = F[1] = 1;
    for (ll i = 2; i <= 1000000; i++)
        F[i] = (F[i - 1] * 1LL * i) % mod;
}
ll ncr(ll n, ll r)
{
    ll up = F[n] % mod;
    ll d1 = F[n - r] % mod;
    ll d2 = F[r] % mod;
    d1 = mpw(d1, mod - 2, mod) % mod;
    d2 = mpw(d2, mod - 2, mod) % mod;
    up = (up * d1) % mod;
    up = (up * d2) % mod;
    return up;
}

class Solution {
public:
    int waysToReachStair(int k) {
        ix();
         ll ans=0;
         rep(i,0,32){
             ll twsum=pw(2,i);
             if(twsum<k)
                 continue;
             ll deg=k-twsum;
             deg=abs(deg);
             ll x=i;
             if(x+1<deg || deg<0)
                 continue;
             ans+=ncr(x+1,deg);
         }
        return (int)ans;
    }
};