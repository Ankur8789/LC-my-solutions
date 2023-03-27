class Solution {
    int res = 0;
    vector<int> nodes;
public:
    void dfs(vector<int>& edges, int src, vector<int>& vis, int& count, vector<int>& dfsVis) 
    {
        
        if(dfsVis[src]) {
            
            res = max(res,count-nodes[src]+1);
            return;
        }
        
        if(vis[src])return;
        
        dfsVis[src] = 1;
        vis[src] = 1;
        
        count++;
        nodes[src] += count;
        
        if(edges[src] != -1)dfs(edges,edges[src],vis,count,dfsVis);
        
        dfsVis[src] = 0;
        
    }
    int longestCycle(vector<int>& edges) {
        
        int n = size(edges);
        nodes.resize(n);
        
        vector<int> vis(n),dfsVis(n);
        
        for(int i = 0; i < n; i++) {
            int count = 0;
            if(vis[i] == 0)dfs(edges,i,vis,count,dfsVis);
        }
        
        return res == 0 ? -1 : res;
    }
};