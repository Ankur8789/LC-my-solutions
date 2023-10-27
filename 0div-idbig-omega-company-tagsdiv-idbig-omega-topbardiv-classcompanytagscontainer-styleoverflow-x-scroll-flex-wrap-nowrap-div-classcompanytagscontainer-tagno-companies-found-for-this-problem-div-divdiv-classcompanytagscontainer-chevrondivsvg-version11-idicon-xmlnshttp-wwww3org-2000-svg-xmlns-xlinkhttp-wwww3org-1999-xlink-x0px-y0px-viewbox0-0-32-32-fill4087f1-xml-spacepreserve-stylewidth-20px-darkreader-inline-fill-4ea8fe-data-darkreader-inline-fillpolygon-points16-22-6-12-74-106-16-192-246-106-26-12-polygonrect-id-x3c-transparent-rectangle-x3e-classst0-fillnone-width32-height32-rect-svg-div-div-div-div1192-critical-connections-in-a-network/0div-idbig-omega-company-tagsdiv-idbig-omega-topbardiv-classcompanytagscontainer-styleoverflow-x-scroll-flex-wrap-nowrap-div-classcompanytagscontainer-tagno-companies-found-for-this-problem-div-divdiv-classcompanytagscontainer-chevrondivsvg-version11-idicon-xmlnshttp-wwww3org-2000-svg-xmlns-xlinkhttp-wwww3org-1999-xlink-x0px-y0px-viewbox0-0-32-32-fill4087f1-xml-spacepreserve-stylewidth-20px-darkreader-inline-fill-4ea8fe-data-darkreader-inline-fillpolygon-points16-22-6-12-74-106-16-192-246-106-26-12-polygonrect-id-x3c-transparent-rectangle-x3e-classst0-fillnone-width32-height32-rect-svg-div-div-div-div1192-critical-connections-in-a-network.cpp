int n; // number of nodes


vector<bool> visited;
vector<int> tin, low;
vector<vector<int>> ans;
int timer;
unordered_map<int,vector<int>> adj;
void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                ans.push_back({v,to});
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}
class Solution 
{
public:
    vector<vector<int>> criticalConnections(int m, vector<vector<int>>& connections) 
    {
        adj.clear();
        ans.clear();
        n=m;
       for(auto t: connections)
       {
          int u=t[0];
          int v=t[1];
          adj[u].push_back(v);
          adj[v].push_back(u);
       }
       find_bridges();
       return ans;
    }
};