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
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int s, int e) {
        umap<ll,vector<pair<ll,ld>>> adj;
        ll m=edges.size();
        rep(i,0,m){
            ll u=edges[i][0],v=edges[i][1];
            ld prob=succProb[i];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        vector<ld> pb(n,0);
        pb[s]=1;
        multiset<pair<ld,ll>> ms;
        ms.insert({1.0,s});
        while(ms.size()){
            auto pr=*--ms.end();
            ms.erase(--ms.end());
            ld prob=pr.fi;
            ll u=pr.se;
            for(auto x: adj[u]){
                ll v=x.first;
                ld sp=x.second;
                if(prob*sp>pb[v]){
                    if(ms.count({pb[v],v}))
                        ms.erase(ms.find({pb[v],v}));
                    pb[v]=prob*sp;
                    ms.insert({pb[v],v});
                }
            }
        }
        return pb[e];
    }
};