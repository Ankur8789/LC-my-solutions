class Solution {
public:
    typedef long long ll;
    bool check(ll mid,string s,ll k,ll a,ll b,ll c)
    {   if(mid>=s.length() && a>=k && b>=k && c>=k)
        return true;
        ll ax=0,bx=0,cx=0;
         ll n=s.length(),i=0,j=0;
        while(j<s.length())
        {    
            if(s[j]=='a')
                ax++;
            else if(s[j]=='b')
                bx++;
            else
                cx++;
             if(j-i+1<mid)
                 j++;
            else if(j-i+1==mid)
            {
                if((a-ax)>=k && (b-bx)>=k && (c-cx)>=k)
                    return true;
                if(s[i]=='a')
                ax--;
                else if(s[i]=='b')
                bx--;
                else
                cx--;
                i++;
                j++;
                
            }
        }
        return false;
    }
    int takeCharacters(string s, int k) 
    {
       ll a=0,b=0,c=0,ans=-1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a')
                a++;
            else if(s[i]=='b')
                b++;
            else
                c++;
        }
        
        ll l=1,r=s.size();
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(check(mid,s,k,a,b,c))
            {
                ans=s.length()-mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        if(ans==-1)
        {
            if(a>=k && b>=k && c>=k)
                ans=s.length();
        }
        return ans;
    }
};