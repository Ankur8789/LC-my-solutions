class Solution {
public:
    vector<int> adj[101];
    int vis[101];
    double f(int x,int tm,int tg,int ct,int par)
    {
        // if(ct>tm)
        //     return 0;
        
        if(ct==tm)
        {
            if(x==tg)
               return 1;
        }
        
        vector<int> vx;
        for(auto t: adj[x])
        {
            if(t==par)
                continue;
            vx.push_back(t);
        }
        if(vx.size()==0)
        {
            if(ct<tm)
            {
                if(x==tg)
                    return 1;
                else
                    return 0;
            }
            else
                return 0;
        }
        double ans=0;
        for(auto t: vx)
        {
            ans+=f(t,tm,tg,ct+1,x)/vx.size();
        }
        return ans;
    
    }
    double frogPosition(int n, vector<vector<int>>& edges, int tm, int tg) 
    {
        for(auto t: edges)
        {
            adj[t[0]].push_back(t[1]);
            adj[t[1]].push_back(t[0]);
        }
        double ans=f(1,tm,tg,0,-1);
        return ans;
        
    }
};