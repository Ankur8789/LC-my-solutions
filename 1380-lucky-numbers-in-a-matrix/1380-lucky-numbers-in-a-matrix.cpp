class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix)
    {
        vector<int> ans;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                int mn=INT_MAX;
                int mx=INT_MIN;
                for(int k=0;k<matrix[0].size();k++)
                mn=min(mn,matrix[i][k]);
                for(int k=0;k<matrix.size();k++)
                mx=max(mx,matrix[k][j]);
                if(mn==matrix[i][j] && mx==matrix[i][j])
                    ans.push_back(matrix[i][j]);

            }
        }
        return ans;
    }
};