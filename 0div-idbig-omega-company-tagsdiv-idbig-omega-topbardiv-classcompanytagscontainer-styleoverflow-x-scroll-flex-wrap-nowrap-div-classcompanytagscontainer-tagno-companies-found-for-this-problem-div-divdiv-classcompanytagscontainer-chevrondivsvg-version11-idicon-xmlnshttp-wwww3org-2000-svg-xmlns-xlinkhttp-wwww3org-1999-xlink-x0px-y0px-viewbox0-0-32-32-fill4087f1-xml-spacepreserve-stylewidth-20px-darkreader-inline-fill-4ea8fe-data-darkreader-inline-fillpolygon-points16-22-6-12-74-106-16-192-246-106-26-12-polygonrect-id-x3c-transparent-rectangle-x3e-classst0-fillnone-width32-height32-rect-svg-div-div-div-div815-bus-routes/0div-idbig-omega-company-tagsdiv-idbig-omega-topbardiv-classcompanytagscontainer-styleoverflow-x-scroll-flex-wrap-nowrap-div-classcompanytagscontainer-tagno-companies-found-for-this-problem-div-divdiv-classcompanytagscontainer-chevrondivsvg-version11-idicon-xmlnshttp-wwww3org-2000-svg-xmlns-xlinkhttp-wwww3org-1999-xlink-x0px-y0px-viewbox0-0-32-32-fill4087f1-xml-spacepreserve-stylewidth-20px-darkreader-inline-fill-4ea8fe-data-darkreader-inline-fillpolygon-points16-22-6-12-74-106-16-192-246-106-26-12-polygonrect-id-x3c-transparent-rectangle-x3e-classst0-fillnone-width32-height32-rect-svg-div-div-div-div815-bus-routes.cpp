class Solution {
public:
    const static int maxn=1e6+1;;
    
    vector<int> adj[maxn];
    int numBusesToDestination(vector<vector<int>>& rt, int so, int tg) 
    {
        if(so==tg)
            return 0;
        
        for(int i=0;i<rt.size();i++)
        {
            for(int j=0;j<rt[i].size();j++)
            {
                adj[rt[i][j]].push_back(i);
            }
        }
        int dis[maxn];
        memset(dis,-1,sizeof(dis));
      //  cout<<dis[tg]<<endl;
        set<int> bs,bsstp;
        dis[so]=0;
        queue<int> q;
        q.push(so);
        bsstp.insert(so);
        while(q.size()>0)
        {
            int x=q.front();
            q.pop();
            for(auto bus: adj[x])
            {
                if(bs.find(bus)==bs.end())
                {   
                    bs.insert(bus);
                    for(auto busstop: rt[bus])
                    {
                        if(bsstp.find(busstop)==bsstp.end())
                        {
                            bsstp.insert(busstop);
                            dis[busstop]=dis[x]+1;
                            q.push(busstop);
                        }
                    }
                }
            }
        }
       // cout<<dis[tg]<<endl;
        if(dis[tg]==-1)
            return -1;
        else
            return dis[tg];
        
        
       
    }
};