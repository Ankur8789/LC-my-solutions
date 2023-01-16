class Solution {
public:
    int dis[201][201];
    int visA[201][201];
    int visP[201][201];
    void dfs(int i,int j,vector<vector<int>>& h,bool pacific)
    {
        // if(i<0 || j<0 || i>=h.size() || i>=h[0].size())
        //     return ;
        if(pacific)
        {
            if(visP[i][j]==1)
                return ;
            visP[i][j]=1;
            if(i+1<h.size() && h[i+1][j]>=h[i][j])
            dfs(i+1,j,h,1);
            if(i-1>=0 && h[i-1][j]>=h[i][j])
            dfs(i-1,j,h,1);
            if(j+1<h[0].size() && h[i][j+1]>=h[i][j])
            dfs(i,j+1,h,1);
            if(j-1>=0 && h[i][j-1]>=h[i][j])
            dfs(i,j-1,h,1);
                        
        }
        else
        {
            if(visA[i][j]==1)
                return ;
             visA[i][j]=1;
            if(i+1<h.size() && h[i+1][j]>=h[i][j])
            dfs(i+1,j,h,0);
            if(i-1>=0 && h[i-1][j]>=h[i][j])
            dfs(i-1,j,h,0);
            if(j+1<h[0].size() && h[i][j+1]>=h[i][j])
            dfs(i,j+1,h,0);
            if(j-1>=0 && h[i][j-1]>=h[i][j])
            dfs(i,j-1,h,0);
        }    
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) 
    {
        vector<vector<int>> ans;
        int m=h.size();
        int n=h[0].size();
       // memset(dis,0,sizeof(dis));
        for(int i=0;i<m;i++)dfs(i,0,h,1);
        for(int i=0;i<n;i++)dfs(0,i,h,1);
        for(int i=0;i<n;i++)dfs(m-1,i,h,0);
        for(int i=0;i<m;i++)dfs(i,n-1,h,0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {   cout<<visA[i][j]<<visP[i][j]<<" ";
                if(visA[i][j]==1 && visP[i][j]==1)
                {   
                    ans.push_back({i,j});
                }
            }
            cout<<endl;
        }
        return ans;
              
        
    }
};