class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> ideg(n);
        unordered_map<int,vector<int>> adj;
        for(auto x:pre){
            int v=x[1],u=x[0];
            adj[v].push_back(u);
            ideg[u]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(ideg[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(q.size()){
            auto x=q.front();
            q.pop();
            cnt++;
            for(auto v: adj[x]){
                ideg[v]--;
                if(ideg[v]==0){
                    q.push(v);
                }
            }
        }
        return cnt==n;
    }
};