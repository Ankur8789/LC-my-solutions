class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        // int n=grid[0].size();
        int cc=0;
        unordered_map<int,vector<int>> row,col;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                row[i].push_back(grid[i][j]);
                col[j].push_back(grid[i][j]);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;++j)
            {
                if(row[i]==col[j])
                    cc++;
            }
        }
        return cc;
        
    }
};