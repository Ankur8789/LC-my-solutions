class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges)
    {
        vector<int> ideg(n);
        unordered_map<int,vector<int>> adj;
        for(auto t:edges)
        {
           adj[t[0]].push_back(t[1]);
            ideg[t[1]]++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(ideg[i]==0)
                ans.push_back(i);
        }
        return ans;
    }
};