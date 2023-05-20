class Solution {
public:
   unordered_map<int,vector<pair<int,double>>> adj;
    double ans;
    void dfs(int x,int y,vector<int>& vis,double val,bool& h)
    {
        vis[x]=1;
        if(x==y)
        {
            h=true;
            ans=val;
            return ;
        }
        for(auto t: adj[x])
        {
            if(vis[t.first]==0)
            {
                dfs(t.first,y,vis,val*t.second,h);
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& q) 
    {   
        map<string,int> mp;
        int k=1;
        for(int i=0;i<eq.size();i++)
        {
            string a=eq[i][0];
            string b=eq[i][1];
            // cout<<a<<" "
            if(mp.find(a)==mp.end())
            {
                mp[a]=k++;
            }
            if(mp.find(b)==mp.end())
            {
                mp[b]=k++;
            }
           adj[mp[a]].push_back({mp[b],val[i]});
           adj[mp[b]].push_back({mp[a],1.0/val[i]});
        }
        ans=1;
        vector<double> anss;
        for(int i=0;i<q.size();i++)
        {
            bool h=false;
            vector<int> vis(mp.size()+1);
            if(mp.find(q[i][0])==mp.end() || mp.find(q[i][1])==mp.end())
            {
                anss.push_back(-1.0);
                continue;
            }
            dfs(mp[q[i][0]],mp[q[i][1]],vis,1,h);
            if(h)
            anss.push_back(ans);
            else
            anss.push_back(-1.0);
            ans=1;
            
        }
        return anss;
            

        
    }
};