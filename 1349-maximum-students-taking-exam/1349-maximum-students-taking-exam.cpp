class Solution {
public:
    vector<pair<int,int>> dirs={{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
    int dp[9][9][1<<9][1<<9];
    bool check(int x,int y,int msk,vector<vector<char>>& seats)
    {
        if(x<0 || y<0 || x>=seats.size() || y>=seats[0].size())
            return 1;
        if(seats[x][y]=='#')
            return 1;
        if(((msk>>x)&1)==0)
            return 1;
        return 0;
        
    }
    int f(int i,int j,int premsk,int currmsk,vector<vector<char>>& seats)
    {
        if(i==seats.size() || j==seats[0].size())
            return 0;
        if(dp[i][j][premsk][currmsk]!=-1)
            return dp[i][j][premsk][currmsk];
        int ans=0;
        if(seats[i][j]!='#' && check(i,j-1,premsk,seats) && check(i-1,j-1,premsk,seats) && check(i+1,j-1,premsk,seats))
        {
            ans=max(ans,1+f(i+1,j,premsk,currmsk|(1<<i),seats));
            ans=max(ans,1+f(0,j+1,currmsk|(1<<i),0,seats));
            ans=max(ans,f(i+1,j,premsk,currmsk,seats));
            ans=max(ans,f(0,j+1,currmsk,0,seats));
        }
        else
        {
            ans=max(ans,f(i+1,j,premsk,currmsk,seats));
            ans=max(ans,f(0,j+1,currmsk,0,seats));
        }
        return dp[i][j][premsk][currmsk]=ans;
       
    }
    int maxStudents(vector<vector<char>>& seats) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=f(0,0,0,0,seats);
        return ans;
    }
};