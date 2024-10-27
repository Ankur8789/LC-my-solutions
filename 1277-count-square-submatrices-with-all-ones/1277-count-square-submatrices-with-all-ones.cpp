class Solution {
public:
    int countSquares(vector<vector<int>>& matrix){   
        int n=matrix.size();
        int m=matrix[0].size();
        int t[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0)
                    t[i][j]=matrix[i][j];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){ 
                if(matrix[i][j]==0)
                 t[i][j]=0;
                else
                 t[i][j]=min({t[i-1][j],t[i][j-1],t[i-1][j-1]})+1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
             ans+=t[i][j];
        }
        return ans;
    }
};