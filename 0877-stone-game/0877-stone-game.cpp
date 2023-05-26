class Solution {
public:
     int t[501][501][3];
   int f(int i,int j,vector<int>& piles,int x)
   {
       if(i>j)
       return 0;
       if(t[i][j][x]!=-1)
       return t[i][j][x];
       if(x==1)
        return t[i][j][x]=max(piles[i]+f(i+1,j,piles,0),piles[j]+f(i,j-1,piles,0));
       
       else
       return t[i][j][x]=min(piles[i]+f(i+1,j,piles,0),piles[j]+f(i,j-1,piles,0));
   }
    bool stoneGame(vector<int>& piles) 
    {  memset(t,-1,sizeof(t));
        int s=0;
        for(int i=0;i<piles.size();i++)
        s+=piles[i];
        int ans=f(0,piles.size()-1,piles,1);
        if(s-ans<=ans)
        return true;
        else
        return false;
    }
};