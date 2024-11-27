class Solution {
public:
    unordered_map<int,vector<int>> adj;
    int djk(int n){
        vector<int> dis(n,1e9);
        dis[0]=0;
        queue<int> q;
        q.push(0);
        while(q.size()){
            auto u=q.front();
            q.pop();
            for(auto v: adj[u]){
                if(dis[v]!=1e9)continue;
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
        return dis[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
            // adj[i+1].push_back(i);
        }
        vector<int> ans;
        for(auto x: queries){
            int u=x[0],v=x[1];
            adj[u].push_back(v);
            // adj[v].push_back(u);
            ans.push_back(djk(n));
        }
        return ans;
    }
};