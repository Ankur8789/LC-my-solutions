class Solution {
public:
    int diameter(int root,unordered_map<int,vector<int>>& adj) {
        int ans = 0;
        dfs(root,adj,ans,-1);
        return ans;
    }

    int dfs(int root,unordered_map<int,vector<int>>& adj,int& ans,int par) {
        int m1 = 0, m2 = 0;
        for (auto child : adj[root]) {
            if(child == par)
                continue;
            int t = dfs(child,adj,ans,root);
            if (t > m1) {
                m2 = m1;
                m1 = t;
            } else if (t > m2)
                m2 = t;
        }
        // cout<<ans<<endl;
        ans = max(ans, m1 + m2);
        return 1 + m1;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,vector<int>> adj1,adj2;
        for(auto x: edges1)
        {
            adj1[x[0]].push_back(x[1]);
            adj1[x[1]].push_back(x[0]);
        }
        for(auto x: edges2)
        {
            adj2[x[0]].push_back(x[1]);
            adj2[x[1]].push_back(x[0]);
        }
        int d1=diameter(0,adj1);
        int d2=diameter(0,adj2);
        // cout<<d1<<" "<<d2<<endl;
        int l1=(d1+1)/2;
        int r1=d1-l1;
        int l2=(d2+1)/2;
        int r2=d2-l2;
        return max({d1,d2,l1+l2+1,l1+r2+1,l2+r1+1});
        
    }
};