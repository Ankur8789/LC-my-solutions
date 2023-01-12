class Solution {
public:
    vector<int> adj[100001];
    int vis[100001];
    vector<int> ans;
    vector<int> f(int x,string& labels)
    {
        vis[x]=1;
        vector<int> freq(26,0);
        freq[labels[x]-'a']++;
        for(auto t: adj[x])
        {
            if(vis[t]==0)
            {
                vector<int> temp=f(t,labels);
                for(int i=0;i<26;i++)
                    freq[i]+=temp[i];
                
            }
        }
        ans[x]=freq[labels[x]-'a'];
        return freq;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) 
    {  
        ans.resize(n);
        for(auto t: edges)
        {
            adj[t[1]].push_back(t[0]);
            adj[t[0]].push_back(t[1]);
        }
        
        
        f(0,labels);
        return ans;
    }
};