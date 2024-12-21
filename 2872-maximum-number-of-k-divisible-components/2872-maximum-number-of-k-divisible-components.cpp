class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_map<int,int> val;
    int dfs(int u,int par,int& ans,int k){
        int sum=0;
        sum+=val[u];
        sum%=k;
        for(auto v: adj[u]){
            if(v==par)
                continue;
            sum+=dfs(v,u,ans,k);
            sum%=k;
        }
        if(sum==0 && u!=0){
            ans++;
            return 0;
        }
        else{
            return sum;
        }
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        for(auto x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        for(int i=0;i<values.size();i++){
            val[i]=values[i];
        }
        int ans=0;
        dfs(0,-1,ans,k);
        ans+=1;
        return ans;
    }
};