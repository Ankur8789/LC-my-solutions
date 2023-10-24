//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
      vector <int> maximumDistance(vector<vector<int>> edges,int v,int e,int src)
      {
         unordered_map<int,vector<pair<int,int>>> adj;
         for(auto t: edges)
         {
             int u=t[0];
             int v=t[1];
             int wt=t[2];
             adj[u].push_back({v,wt});
         }
         vector<int> dis(v,INT_MIN);
         queue<pair<int,int>> q;
         dis[src]=0;
         q.push({0,src});
         while(q.size())
         {
             auto x=q.front();
             q.pop();
             int d=x.first;
             int u=x.second;
             for(auto t: adj[u])
             {
                 int v=t.first;
                 int wt=t.second;
                 if(dis[v]<d+wt)
                 {
                    //  if(ms.count({v,dis[v]}))
                    //   ms.erase({v,dis[v]});
                     dis[v]=d+wt;
                     q.push({dis[v],v});
                 }
             }
         }
         return dis;
         
      }
};

//{ Driver Code Starts.

int main() {
  
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
 
}
// } Driver Code Ends