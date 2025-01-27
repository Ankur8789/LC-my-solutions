class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,set<int>> pars;
        vector<int> ideg(n);
        for(auto x: pre){
            int u=x[0],v=x[1];
            adj[u].push_back(v);
            ideg[v]+=1;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(ideg[i]==0){
                q.push(i);
                set<int> st;
                pars[i]=st;
            }
        }
        while(q.size()){
            auto u=q.front();
            q.pop();
            for(auto v: adj[u]){
                ideg[v]--;
                if(ideg[v]==0)
                    q.push(v);
                if(pars.count(v)){
                    set<int> st=pars[u];
                    for(auto x: st)
                        pars[v].insert(x);
                    pars[v].insert(u);
                }
                else{
                    set<int> st=pars[u];
                    st.insert(u);
                    pars[v]=st;
                }
            }
        }
        vector<bool> ans;
        for(auto x: queries){
            int u=x[0],v=x[1];
            if(pars[v].count(u))ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};