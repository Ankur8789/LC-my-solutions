class Solution {
public:
     vector<int> adj[100001];
    int vis1[100001];
    int vis2[100001];
    int dis1[100001];
    int dis2[100001];
    int closestMeetingNode(vector<int>& edges, int node1, int node2)
    {     //building graph
          for(int i=0;i<edges.size();i++)
          {
              if(edges[i]==-1)
                  continue;
              adj[i].push_back(edges[i]);
          }
        //1st bfs
         queue<int> q1;
        dis1[node1]=0;
        vis1[node1]=1;
        q1.push(node1);
        int k=1;
        while(q1.size()>0)
        {
            int sz=q1.size();
            while(sz--)
            {
                int x=q1.front();
                q1.pop();
                for(auto t: adj[x])
                {
                    if(vis1[t]==0)
                    {
                        dis1[t]=k;
                        q1.push(t);
                        vis1[t]=1;
                    }
                }
            }
            k++;
        }
        //2nd bfs
        queue<int> q2;
        dis2[node2]=0;
        vis2[node2]=1;
        q2.push(node2);
        k=1;
        while(q2.size()>0)
        {
            int sz=q2.size();
            while(sz--)
            {
                int x=q2.front();
                q2.pop();
                for(auto t: adj[x])
                {
                    if(vis2[t]==0)
                    {
                        dis2[t]=k;
                        q2.push(t);
                        vis2[t]=1;
                    }
                }
            }
            k++;
        }
            int mx=INT_MAX,idx=-1;
        for(int i=0;i<edges.size();i++)
        {  //cout<<dis1[i]<<" "<<dis2[i]<<endl;
            if(vis1[i]==1 && vis2[i]==1)
            {
                if(max(dis1[i],dis2[i])<mx)
                {
                    mx=max(dis1[i],dis2[i]);
                    idx=i;
                }
            }
        }
        return idx;
        
        
        
    }
};