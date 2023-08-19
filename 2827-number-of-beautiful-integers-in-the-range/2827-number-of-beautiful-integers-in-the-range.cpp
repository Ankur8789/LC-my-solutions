int pw(int a, int n)
{
    int res = 1;
    while (n)
    {
        if (n % 2)
        {
            res *= a;
            n--;
        }
        else
        {
            a *= a;
            n /= 2;
        }
    }
    return res;
}
class Solution {
public:
    int dp[10][2][21][21][21][2];
    int f(int i,int tight,int rem,string& s,int k,int od,int ev,int trail)
    {
        if(i==s.size())
        {
            if(rem==0 && od==ev)
                return 1;
            else
                return 0;
        }
        if(dp[i][tight][rem][od][ev][trail]!=-1)
            return dp[i][tight][rem][od][ev][trail];
        int cap=s.size()-i-1;
        int ub=9;
        if(tight)
            ub=s[i]-'0';
        int ans=0;
        for(int idx=0;idx<=ub;idx++)
        {
           if(trail)
           {
               if(idx==0)
                   ans+=f(i+1,tight&(idx==ub),rem,s,k,od,ev,trail);
               else
               {
                   if(idx&1)
                       ans+=f(i+1,tight&(idx==ub),(rem+idx*pw(10,cap))%k,s,k,od+1,ev,trail^1);
                   else
                       ans+=f(i+1,tight&(idx==ub),(rem+idx*pw(10,cap))%k,s,k,od,ev+1,trail^1);
               }
           }
           else
           {
                  if(idx&1)
                       ans+=f(i+1,tight&(idx==ub),(rem+idx*pw(10,cap))%k,s,k,od+1,ev,trail);
                   else
                       ans+=f(i+1,tight&(idx==ub),(rem+idx*pw(10,cap))%k,s,k,od,ev+1,trail);
           }
        }
        return dp[i][tight][rem][od][ev][trail]=ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) 
    {
        string a=to_string(low);
        string b=to_string(high);
        memset(dp,-1,sizeof(dp));
        int ans=f(0,1,0,b,k,0,0,1);
        memset(dp,-1,sizeof(dp));
        ans-=f(0,1,0,a,k,0,0,1);
        if(low%k==0)
        {
            int od=0,ev=0;
            for(auto t: a)
            {
                int val=t-'a';
                if(val&1)
                    od++;
                else
                    ev++;
            }
            if(od==ev)
                ans++;
        }
        return ans;
    }
};