class Solution {
public:
     vector<int> adj[100001];
    int res;
    int f(int x,string& s,char pre)
    {
      
        int mx1=0,mx2=0;
        for(auto t: adj[x])
        {
            int p=f(t,s,s[x]);
            cout<<p<<" ";
            if(s[t]==s[x])
                continue;
            if(p>mx1)
            {
                mx2=mx1;
                mx1=p;
            }
            else if(p>mx2)
            {
                mx2=p;
            }
        }
        res=max(res,mx1+mx2+1);
        return max(mx1,mx2)+1;
        
    }
    int longestPath(vector<int>& parent, string s) 
    {
        for(int i=1;i<parent.size();i++)
        {
            adj[parent[i]].push_back(i);
        }
        res=0;
       int ans=f(0,s,'@');
        return res;
    }
};