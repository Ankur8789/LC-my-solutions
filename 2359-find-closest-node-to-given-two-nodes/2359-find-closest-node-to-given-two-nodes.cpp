void bfs(unordered_map<int,vector<int>> &adj,vector<int> &dist,int src)
{
    queue<int> q;
    q.push(src);
    dist[src]=0;
    while(q.size())
    {
        int curr=q.front();
        q.pop();
        for(auto child:adj[curr])
        {
            if(dist[child]>dist[curr]+1)
            {
                dist[child]=dist[curr]+1;
                q.push(child);
            }
        }
    }
}

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2){
        unordered_map<int,vector<int>> adj;
        int n=edges.size();
        for(int i=0;i<n;i++)
        {
            if(edges[i]==-1)
                continue;
            adj[i].push_back(edges[i]);
        }
        vector<int> dist1(n,1e9);
        vector<int> dist2(n,1e9);
        bfs(adj,dist1,node1);
        bfs(adj,dist2,node2);
        for(int i=0;i<n;i++)
        {
            // cout<<dist1[i]<<" ";
        }
        cout<<endl;
        int ans=-1,val=1e9;
        for(int i=0;i<n;i++)
        {
            // cout<<dist2[i]<<" ";
            if(dist1[i]!=1e9&&dist2[i]!=1e9)
            {
                int value=max(dist1[i],dist2[i]);
                if(val>value)
                {
                    val=value;
                    ans=i;
                }
            }
        }
        // cout<<endl;
        return ans;
    }
};
