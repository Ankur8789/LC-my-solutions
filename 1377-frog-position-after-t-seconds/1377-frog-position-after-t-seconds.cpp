class Solution {
public:
    typedef long double ld;
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        unordered_map<int,vector<int>> adj;
        for(auto x : edges){
            int u = x[0] , v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ld ans = 0.0;
        vector<int> time(n+1 , 1e9);
        vector<ld> prob(n+1);
        prob[1] = 1.0;
        time[1] = 0;
        queue<int> q;
        q.push(1);
        while(q.size() > 0){
            auto u = q.front();
            q.pop();
            int sz = adj[u].size();
            if(u != 1)
                sz--;
            for(auto v : adj[u]){
                if(time[v] != 1e9)
                    continue;
                ld rem = 1.0/ld(sz);
                prob[v] = prob[u] * rem;
                time[v] = time[u] + 1;
                q.push(v);
            }
        }
        
        if(time[target] == t || (adj[target].size() == 1 && target!=1 && time[target] <= t) || (adj[1].size() == 0))
            return prob[target];
        else
            return 0.0;
    }
};