class Solution {
public:
    bool canFinish(int nc, vector<vector<int>>& pre) 
    {
        unordered_map<int,vector<int>> adj;
        vector<int> ideg(nc,0);
        for(auto t: pre)
        {
            adj[t[1]].push_back(t[0]);
            ideg[t[0]]++;
        }
        queue<int> q;
        int cc=0;
        for(int i=0;i<nc;i++)
        {
            if(ideg[i]==0)
                q.push(i);
        }
        while(q.size()>0)
        {
            auto t=q.front();
            q.pop();
            cc++;
            for(auto x: adj[t])
            {
                ideg[x]--;
                if(ideg[x]==0)
                    q.push(x);
            }
        }
        return cc==nc;
    }
};