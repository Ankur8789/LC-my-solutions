class Solution {
public:
    bool f(int i,int j,vector<vector<int>>& vis,vector<vector<char>>& v,string& s,int k)
    {  
        if(k==s.size())
            return true;
        if(i<0 || j<0 || i>=v.size() || j>=v[0].size())
            return false;
        if(vis[i][j]==1)
            return false;
        if(s[k]!=v[i][j])
            return false;
        vis[i][j]=1;
        bool a=f(i+1,j,vis,v,s,k+1)||f(i-1,j,vis,v,s,k+1)||f(i,j+1,vis,v,s,k+1)||f(i,j-1,vis,v,s,k+1);
         vis[i][j]=0;
        return a;
        
    }
    bool exist(vector<vector<char>>& v, string s) 
    {   vector<vector<int>> vis(v.size(),vector<int>(v[0].size(),0));
        for(int i=0;i<v.size();i++)
        {
          for(int j=0;j<v[0].size();j++)
          {
              if(v[i][j]==s[0])
              {
                  bool ans=f(i,j,vis,v,s,0);
                  if(ans)
                      return true;
              }
          }
        }
        return false;
    }
};