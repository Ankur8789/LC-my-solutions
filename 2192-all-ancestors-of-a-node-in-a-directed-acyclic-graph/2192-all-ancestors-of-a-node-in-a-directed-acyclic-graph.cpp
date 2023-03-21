class Solution {
public:
    vector<int> adj[1001];
    int ideg[1001];
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& e) 
    {   
       //basically it is brute solution
       for(int i=0;i<101;i++)ideg[i]=0;
       for(auto t: e)
       {
           adj[t[0]].push_back(t[1]);
           ideg[t[1]]++;
       }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(ideg[i]==0)
                q.push(i);
        }
       set<int> ms[n]; 
        while(q.size()>0)
        {
            int x=q.front();
            q.pop();
            for(auto t: adj[x])
            {  
                ideg[t]--;
                if(ideg[t]==0)
                    q.push(t);
                ms[t].insert(x);
                for(auto it:ms[x])
                {
                    ms[t].insert(it);
                }
            }
            
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            for(auto t:ms[i])
            {
                temp.push_back(t);
            }
            ans.push_back(temp);
        }
        return ans;
        
       
    }
};