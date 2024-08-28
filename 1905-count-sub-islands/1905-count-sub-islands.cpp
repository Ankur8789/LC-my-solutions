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
ll temp=0;
set<ll> st;
class Solution {
public:
    vector<pll> dirs={{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(ll x,ll y,vector<vector<ll>>& vis,vector<vector<int>>& g){
        vis[x][y]=temp;
        for(auto t: dirs){
            ll u=x+t.fi;
            ll v=y+t.se;
            if(u>=0 && v>=0 && u<g.size() && v<g[0].size() && vis[u][v]==0 && g[u][v])
                dfs(u,v,vis,g);
        }
    }
    void check(ll x,ll y,vector<vector<ll>>& vis1,vector<vector<ll>>& vis2,vector<vector<int>>& g,bool& res){
        vis2[x][y]=1;
        if(vis1[x][y]==0)
            res=false;
        st.insert(vis1[x][y]);
        for(auto t: dirs){
            ll u=x+t.fi;
            ll v=y+t.se;
            if(u>=0 && v>=0 && u<g.size() && v<g[0].size() && vis2[u][v]==0 && g[u][v])
                check(u,v,vis1,vis2,g,res);
        }
    }
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        ll m=g1.size(),n=g1[0].size();
        vector<vector<ll>> vis1(m,vector<ll>(n,0));
        vector<vector<ll>> vis2=vis1;
        temp=1;
        rep(i,0,m){
            rep(j,0,n){
                if(!vis1[i][j] && g1[i][j]){
                    dfs(i,j,vis1,g1);
                    ++temp;
                }
            }
        }
        ll ans=0;
        rep(i,0,m){
            rep(j,0,n){
                if(!vis2[i][j] && g2[i][j]){
                    bool res=true;
                    st.clear();
                    check(i,j,vis1,vis2,g2,res);
                    ans+= (st.size()==1 &&  res);
                }
            }
        }
        return ans;
    }
};