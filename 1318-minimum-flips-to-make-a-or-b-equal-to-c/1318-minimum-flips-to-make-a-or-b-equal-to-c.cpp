class Solution {
public:
    int minFlips(int a, int b, int c) 
    {  
        int cnt=0;
       for(int i=0;i<32;i++)
       {
           int x=(a>>i)&1;
           int y=(b>>i)&1;
           int z=(c>>i)&1;
           if(z==1)
           {
              if(x==1 || y==1)
                continue;
               else if(x==0 && y==0)
                   cnt+=1;
           }
           else
           {
               if(x==1 && y==1)
                   cnt+=2;
               else if(x==1 && y==0)
                   cnt++;
               else if(x==0 && y==1)
                   cnt++;
               else
                   continue;
           }
       }
        return cnt;
    }
};