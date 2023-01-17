class Solution 
{
public:
int t[100001][5];
int f(int i,int x,string& s)
    {
        if(i==s.length())
        return 0;
        if(t[i][x]!=-1)
        return t[i][x];
        if(x==1)
        {  int a=0,b=0,c=0;
           if(s[i]=='0')
           {
              a=f(i+1,x,s);
              b=f(i+1,0,s);
              c=1+f(i+1,0,s);
              return t[i][x]=min({a,b,c});
           }
           else
           {
               a=f(i+1,x,s)+1;
               b=1+f(i+1,0,s);
               c=f(i+1,0,s);
               return t[i][x]=min({a,b,c});
           }
        }
        else
        {
            if(s[i]=='0')
            return t[i][x]= 1+f(i+1,x,s);
            else
            return t[i][x]=f(i+1,x,s);
        }
    }
    int minFlipsMonoIncr(string s)
     {  memset(t,-1,sizeof(t));
        int x=f(0,1,s);
        return x;
    }
};