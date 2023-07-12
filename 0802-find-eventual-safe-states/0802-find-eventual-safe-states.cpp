class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        unordered_map<int,vector<int>> adj;
        int n=graph.size();
        vector<int> ideg(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[graph[i][j]].push_back(i);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                ideg[adj[i][j]]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(ideg[i]==0)
                q.push(i);
        }
        while(q.size()>0)
        {
            auto x=q.front();
            q.pop();
            ans.push_back(x);
            for(auto t: adj[x])
            {
                ideg[t]--;
                if(ideg[t]==0)
                    q.push(t);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};