class Solution {
public:
    unordered_map<int,vector<int>>Rowlist;
    unordered_map<int,vector<int>>Collist;
    
    void dfs (int index, vector<bool>&visited, vector<vector<int>>&stones)
    {
         visited[index] = true;
        
        for(int i=0;i<Rowlist[stones[index][0]].size();i++)
        {
            if(visited[Rowlist[stones[index][0]][i]])
                continue;
            dfs(Rowlist[stones[index][0]][i],visited,stones);
        }

        for(int i=0;i<Collist[stones[index][1]].size();i++)
        {
            if(visited[Collist[stones[index][1]][i]])
                continue;
            dfs(Collist[stones[index][1]][i],visited,stones);
        }
        
    }
    int removeStones(vector<vector<int>>& stones) 
    {
      
        int n = stones.size();
         vector<bool>visited(n,false);
         for(int i=0;i<n;i++)
        {
            Rowlist[stones[i][0]].push_back(i);
            Collist[stones[i][1]].push_back(i);
        }
         int c = 0;
        for(int i=0;i<n;i++)
        {
            if(visited[i])continue;
            dfs(i,visited,stones);
            c++;
        }
        return n-c;
    }
};