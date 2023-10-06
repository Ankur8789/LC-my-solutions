class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) 
    {
        unordered_map<int,vector<int>> adj;
        int n=colors.size();
        vector<int> ideg(n);
        for(auto t :edges)
        {
            int u=t[0];
            int v=t[1];
            ideg[v]++;
            adj[u].push_back(v);
        }
        vector<vector<int>> col(n,vector<int>(26));
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            col[i][colors[i]-'a']++;
        }
        for(int i=0;i<n;i++)
        {
            if(ideg[i]==0)
                q.push(i);
        }
        int cnt=0;
        while(q.size()>0)
        {
            auto u=q.front();
            cnt++;
            q.pop();
            for(auto v: adj[u])
            {
                ideg[v]--;
                if(ideg[v]==0)
                    q.push(v);
                for(int i=0;i<26;i++)
                {
                    col[v][i]=max(col[v][i],col[u][i]+(colors[v]-'a'==i?1:0));  
                }
            }
        }
        int maxx=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<26;j++)
            {
                // cout<<col[i][j]<<" ";
                maxx=max(maxx,col[i][j]);
            }
            // cout<<endl;
        }
        return cnt==n?maxx:-1;
    }

};