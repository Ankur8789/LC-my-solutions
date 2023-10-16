class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<vector<int>> vec(34);
        for(int i=0;i<=33;i++)
        {
            vec[i].resize(i+1);
            vec[i][0]=1;
            vec[i][i]=1;
        }
        for(int i=0;i<=33;i++)
        {
            for(int j=1;j<vec[i].size()-1;j++)
            {
                int ps=0;
                if(j-1>=0)
                    ps+=vec[i-1][j-1];
                ps+=vec[i-1][j];
                vec[i][j]=ps;
            }
        }
        return vec[rowIndex];
    }
};