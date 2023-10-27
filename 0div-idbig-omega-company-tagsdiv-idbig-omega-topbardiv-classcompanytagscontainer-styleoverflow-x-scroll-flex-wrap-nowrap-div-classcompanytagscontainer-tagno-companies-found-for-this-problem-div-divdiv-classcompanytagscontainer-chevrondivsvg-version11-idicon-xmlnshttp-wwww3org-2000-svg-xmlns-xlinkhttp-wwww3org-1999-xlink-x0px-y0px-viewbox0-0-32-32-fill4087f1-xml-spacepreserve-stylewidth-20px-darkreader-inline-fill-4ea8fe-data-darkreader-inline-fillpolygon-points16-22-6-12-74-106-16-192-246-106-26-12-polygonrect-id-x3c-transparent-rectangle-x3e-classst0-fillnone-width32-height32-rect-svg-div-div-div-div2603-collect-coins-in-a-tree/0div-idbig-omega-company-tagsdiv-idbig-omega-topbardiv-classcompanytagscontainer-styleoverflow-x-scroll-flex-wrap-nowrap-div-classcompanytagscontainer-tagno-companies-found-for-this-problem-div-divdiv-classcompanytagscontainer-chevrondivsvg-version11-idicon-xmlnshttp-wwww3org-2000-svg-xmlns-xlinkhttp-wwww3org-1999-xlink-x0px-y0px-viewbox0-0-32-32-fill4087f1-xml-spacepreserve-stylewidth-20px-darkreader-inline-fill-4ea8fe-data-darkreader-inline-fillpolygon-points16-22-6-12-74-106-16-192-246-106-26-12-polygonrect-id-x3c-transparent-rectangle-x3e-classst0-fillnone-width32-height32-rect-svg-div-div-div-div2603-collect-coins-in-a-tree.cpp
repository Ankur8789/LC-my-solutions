class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_map<int,int> ava;
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) 
    {
        ava.clear();
        adj.clear();
        int n=coins.size();
        vector<int> ideg(n);
        for(auto t: edges)
        {
            int u=t[0];
            int v=t[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            ideg[u]++;
            ideg[v]++;
        }
        for(int i=0;i<coins.size();i++)
        {
            if(coins[i]==1)
                ava[i]++;
        }
        queue<int> trim;
        int m=n;
        for(int i=0;i<n;i++)
        {
            if(ava.find(i)==ava.end() && ideg[i]==1)
                trim.push(i);
        }
        unordered_map<int,int> unw;
        while(trim.size()>0)
        {
            auto x=trim.front();
            trim.pop();
            m--;
            unw[x]++;
            ideg[x]=0;
            for(auto t: adj[x])
            {
                if(unw.find(t)==unw.end() && ideg[t]>=1)
                {
                    ideg[t]--;
                    if(ideg[t]==1 && ava.find(t)==ava.end())
                        trim.push(t);
                }
            }
            
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(ideg[i]==1 && ava.find(i)!=ava.end())
                q.push(i);
        }
        for(int i=0;i<2;i++)
        {
            int sz=q.size();
            while(sz--)
            {
                auto x=q.front();
                m--;
                q.pop();
                ideg[x]=0;
                for(auto t: adj[x])
                {
                    if(unw.find(t)==unw.end())
                    {
                        if(ideg[t]>0)
                        {
                            ideg[t]--;
                            if(ideg[t]==1)
                                q.push(t);
                        }
                    }
                }
                
            }
        }
        int res=(m-1>0)?(2*(m-1)):0;
        return res;
        
         
    }
};