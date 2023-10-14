class Solution
{
public:
    typedef long long ll;
    long long minimumWeight(int n, vector<vector<int>> &edges, int src1, int src2, int dest)
    {
        unordered_map<ll, vector<pair<ll, ll>>> adj, revadj;

        for (auto t : edges)
        {
            ll u = t[0];
            ll v = t[1];
            ll wt = t[2];
            adj[u].push_back({v, wt});
            revadj[v].push_back({u, wt});
        }
        vector<ll> dis1(n, 1e18), dis2(n, 1e18), revdis(n, 1e18);
        multiset<pair<ll, ll>> ms;
        ms.insert({0, src1});
        dis1[src1] = 0;
        while (ms.size() > 0)
        {
            auto t = *ms.begin();
            ms.erase(ms.begin());
            ll u = t.second;
            ll d = t.first;
            for (auto t : adj[u])
            {
                ll v = t.first;
                ll wt = t.second;
                if (dis1[v] > d + wt)
                {
                    if(ms.count({dis1[v],v}))
                    ms.erase({dis1[v], v});
                    dis1[v] = d + wt;
                    ms.insert({dis1[v], v});
                }
            }
        }
        dis2[src2] = 0;
        ms.insert({0, src2});
        while (ms.size() > 0)
        {
            auto t = *ms.begin();
            ms.erase(ms.begin());
            ll u = t.second;
            ll d = t.first;
            for (auto t : adj[u])
            {
                ll v = t.first;
                ll wt = t.second;
                if (dis2[v] > d + wt)
                {
                    if(ms.count({dis2[v],v}))
                    ms.erase({dis2[v], v});
                    dis2[v] = d + wt;
                    ms.insert({dis2[v], v});
                }
            }
        }
        revdis[dest] = 0;
        ms.insert({0, dest});
        while (ms.size() > 0)
        {
            auto t = *ms.begin();
            ms.erase(ms.begin());
            ll u = t.second;
            ll d = t.first;
            for (auto t : revadj[u])
            {
                ll v = t.first;
                ll wt = t.second;
                if (revdis[v] > d + wt)
                {
                    if(ms.count({revdis[v],v}))
                    ms.erase({revdis[v], v});
                    revdis[v] = d + wt;
                    ms.insert({revdis[v], v});
                }
            }
        }
        ll res = 1e18;
        for (ll via = 0; via < n; via++)
        {
            if (dis1[via] != 1e18 && dis2[via] != 1e18 && revdis[via] != 1e18)
                res = min(res, dis1[via] + dis2[via] + revdis[via]);
        }
        return res == 1e18 ? -1 : res;
    }
};