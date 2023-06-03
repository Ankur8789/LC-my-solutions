class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<pair<int,int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int> dist(n,1e9);
        dist[src] =0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});

        while(!q.empty()){
            int stop = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            
            if(stop > K) continue;

            for(auto it : adj[node]){
                int adjNode = it.first;
                int weight = it.second;

                if(cost + weight < dist[adjNode] && stop <= K){
                    dist[adjNode] = cost + weight;
                    q.push({stop+1,{adjNode,dist[adjNode]}});
                }
            }
        }

        if(dist[dst]  == 1e9) return -1;
        return dist[dst];
    }
};