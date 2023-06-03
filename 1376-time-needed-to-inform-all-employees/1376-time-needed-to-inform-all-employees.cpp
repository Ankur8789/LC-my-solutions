class Solution {
public:
    vector<int> adj[100001];
    int vis[100001];
    int time[100001];
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        time[headID]=0;
        for(int i=0;i<manager.size();i++)
        {  if(manager[i]==-1)
            continue;
            adj[manager[i]].push_back(i);
        }
        vis[headID]=1;
        queue<int> q;
        q.push(headID);
        while(q.size()>0)
        {
            int t=q.front();
            q.pop();
            for(int i=0;i<adj[t].size();i++)
            {
                if(vis[adj[t][i]]==0)
                {
                    vis[adj[t][i]]=1;
                    time[adj[t][i]]=time[t]+informTime[t];
                    q.push(adj[t][i]);
                }
            }
        }
        int mx=INT_MIN;
        for(int i=0;i<n;i++)
            mx=max(mx,time[i]);
        return mx;
    }
};