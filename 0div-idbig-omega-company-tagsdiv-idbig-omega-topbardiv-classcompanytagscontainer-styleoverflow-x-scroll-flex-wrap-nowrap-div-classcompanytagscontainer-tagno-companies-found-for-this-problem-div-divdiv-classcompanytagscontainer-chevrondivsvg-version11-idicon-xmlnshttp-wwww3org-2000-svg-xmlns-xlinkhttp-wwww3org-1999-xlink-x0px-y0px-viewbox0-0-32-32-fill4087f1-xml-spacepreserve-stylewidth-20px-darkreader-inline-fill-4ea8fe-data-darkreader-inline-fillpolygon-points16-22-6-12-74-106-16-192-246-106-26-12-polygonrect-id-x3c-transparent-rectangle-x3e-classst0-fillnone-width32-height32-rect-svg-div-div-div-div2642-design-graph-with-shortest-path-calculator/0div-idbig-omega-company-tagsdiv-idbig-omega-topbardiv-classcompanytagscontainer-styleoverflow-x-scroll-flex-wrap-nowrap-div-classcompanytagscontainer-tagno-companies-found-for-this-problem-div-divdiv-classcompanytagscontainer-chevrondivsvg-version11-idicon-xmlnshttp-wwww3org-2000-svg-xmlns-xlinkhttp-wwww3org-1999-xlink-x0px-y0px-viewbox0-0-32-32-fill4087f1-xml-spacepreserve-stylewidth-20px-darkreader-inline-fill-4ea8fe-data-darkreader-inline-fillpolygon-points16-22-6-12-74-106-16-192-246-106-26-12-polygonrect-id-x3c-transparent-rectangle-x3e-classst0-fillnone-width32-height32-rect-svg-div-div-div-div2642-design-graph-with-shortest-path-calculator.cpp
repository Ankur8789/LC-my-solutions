typedef long long ll;
unordered_map<int,vector<pair<int,int>>> adj;
    ll fuck;
class Graph {
public:
    
    Graph(int n, vector<vector<int>>& edges) 
    {
        adj.clear();
       for(auto t: edges)
       {
           adj[t[0]].push_back({t[1],t[2]});
       }
        fuck=n;
    }
    
    void addEdge(vector<int> t) 
    {
         adj[t[0]].push_back({t[1],t[2]});
    }
    
    int shortestPath(int node1, int node2)
    {
    vector<ll> dis(fuck,1e18);
    set<pair<ll, ll>> st;
    dis[node1] = 0;
    st.insert({0, node1});
    while (st.size() > 0)
    {
        pair<ll, ll> p = *st.begin();
        st.erase(st.begin());
        ll wt = p.first;
        ll u = p.second;
        for (auto t : adj[u])
        {
            pair<ll, ll> q = t;
            ll v = q.first;
            ll x = q.second;
            if (dis[v] > dis[u] + x)
            {
                if (st.find({dis[v], v}) != st.end())
                    st.erase({dis[v], v});
                dis[v] = dis[u] + x;
                st.insert({dis[v], v});
            }
        }
    }
        if(dis[node2]==1e18)
            return -1;
        return dis[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */