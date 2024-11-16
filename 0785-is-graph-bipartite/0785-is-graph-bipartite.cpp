class Solution {
public:
    unordered_map<int,vector<int>> adj;
    void dfs(int u,vector<int>& vis,vector<int>& col,int c,bool& res){
        vis[u]=1;
        col[u]=c;
        for(auto v: adj[u]){
            if(vis[v]==0){
                dfs(v,vis,col,c^1,res);
            }
            else{
                if(col[v]==c){
                    res=false;
                    return;
                }
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        for(int i=0;i<n;i++){
            vector<int> tem=graph[i];
            // cout<<i<<"->"<<endl;
            for(auto x: tem){
                // cout<<x<<endl;
                adj[x].push_back(i);
                adj[i].push_back(x);
            }
        }
        vector<int> vis(n),col(n,-1);
        bool res=true;
        for(int i=0;i<n;i++){
            if(vis[i])continue;
            dfs(i,vis,col,0,res);
        }
        return res;
        
    }
};