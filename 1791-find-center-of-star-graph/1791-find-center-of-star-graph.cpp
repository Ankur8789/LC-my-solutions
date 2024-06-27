class Solution {
public:
    int findCenter(vector<vector<int>>& edges) 
    {
        unordered_map<int,int> ideg;
        int n=edges.size()+1;
        int ans=0;
        for(auto x: edges)
        {
            int u=x[0];
            int v=x[1];
            ideg[u]++;
            ideg[v]++;
            if(ideg[u]==n-1)
                ans=u;
            if(ideg[v]==n-1)
                ans=v;
        }
        return ans;
    }
};