class Solution {
public:
    unordered_map<int,set<pair<string,int>>> adj;
    map<string,int> fre;
    unordered_map<int,string> rev;
    map<pair<int,int>,int> mp;
    vector<string> res;
    int n;
    bool dfs(int x)
    {
        if(res.size()==n+1)
            return 1;
        
        // cout<<rev[x]<<" "<<adj[x].size()<<endl;;
        set<pair<string,int>> st=adj[x];
        for(auto t: st)
        {
            if(mp[{x,fre[t.first]}]==0)
                continue;
            mp[{x,fre[t.first]}]--;
            res.push_back(t.first);
            if(dfs(t.second))
                return 1;
             mp[{x,fre[t.first]}]++;
             res.pop_back();
            
            
        }
        return 0;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        n=tickets.size();
        sort(tickets.begin(),tickets.end());
        int k=1;
        fre["JFK"]=0;
        for(auto t: tickets) 
        {
            string u=t[0];
            string v=t[1];
            if(fre.find(u)==fre.end())
                fre[u]=k++;
            if(fre.find(v)==fre.end())
                fre[v]=k++;
            adj[fre[u]].insert({v,fre[v]});
            mp[{fre[u],fre[v]}]++;
        }
        for(auto t: fre)
            rev[t.second]=t.first;
        // for(auto t: adj[fre["SFO"]])
        //     cout<<t.first<<" ";
        res.push_back(rev[0]);
        dfs(0);
        return res;
        
        
        
        
        
        
    }
};