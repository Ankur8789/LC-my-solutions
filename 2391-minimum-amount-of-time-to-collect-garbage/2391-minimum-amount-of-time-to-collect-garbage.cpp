class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) 
    {
        int m=0,g=0,p=0;
         int M=-1,P=-1,G=-1;
         for(int i=0;i<garbage.size();i++)
         {
             for(int j=0;j<garbage[i].length();j++)
             {
                  if(garbage[i][j]=='P')
                  {
                      p++;
                      P=i;
                  }
                 if(garbage[i][j]=='M')
                  {
                      m++;
                      M=i;
                  }
                 if(garbage[i][j]=='G')
                  {
                      g++;
                      G=i;
                  }
             }
             
         }
           int time=0;
             for(int i=0;i<=P-1;i++)
                 time+=travel[i];
             for(int i=0;i<=M-1;i++)
                 time+=travel[i];
             for(int i=0;i<=G-1;i++)
                 time+=travel[i];
             time+=g+p+m;
             return time;

    }
};