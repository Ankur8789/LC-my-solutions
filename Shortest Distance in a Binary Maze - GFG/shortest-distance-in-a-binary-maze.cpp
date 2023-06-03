//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   vector<pair<int,int>>dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool check(int x,int y,vector<vector<int>>& grid)
    {
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size())
            return false;
        if(grid[x][y]==0)
            return false;
        return true;
    }
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> des) 
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dis(m,vector<int>(n,1e9));
        queue<pair<int,int>> q;
        if(grid[source.first][source.second] == 0 || grid[des.first][des.second] ==0)
           return -1;
        dis[source.first][source.second]=0;
        q.push({source.first,source.second});
        while(q.size()>0)
        {
            auto x=q.front();
            q.pop();
            for(auto t: dir)
            {
                int nx=x.first+t.first;
                int ny=x.second+t.second;
                if(check(nx,ny,grid) && dis[nx][ny]>dis[x.first][x.second]+1)
                {
                    q.push({nx,ny});
                    dis[nx][ny]=dis[x.first][x.second]+1;
                }
            }
        }
        if(dis[des.first][des.second]==1e9)
        return -1;
        return dis[des.first][des.second];
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends