class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();

        for (int i = 0; i < row; i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < col; j++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        for (int j = 1; j < col; j++) {
            int cZ = 0;
            for (int i = 0; i < row; i++) {
                if (grid[i][j] == 0) {
                    cZ++;
                }
            }

            if (cZ > row - cZ) {
                for (int i = 0; i < row; i++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        int score=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                int colScore=grid[i][j]<<(col-j-1);
                score+=colScore;
            }
        }
        return score;
    }
};