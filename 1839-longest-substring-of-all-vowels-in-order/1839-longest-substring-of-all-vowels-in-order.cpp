#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
class Solution {
public:
    typedef long long ll;
    int longestBeautifulSubstring(string s) 
    {   fastio();
        ll ax=0,ex=0,ix=0,ox=0,ux=0;
        ll i=0,j=0,n=s.size();
        ll res=0;
        while(j<n)
        {
            if(s[j]=='a')
                ax++;
            if(s[j]=='e')
                ex++;
            if(s[j]=='i')
                ix++;
            if(s[j]=='o')
                ox++;
            if(s[j]=='u')
                ux++;
            //sliding
            if(s[j]=='a')
            {
                while(ex>0 || ix>0 || ox>0 || ux>0)
                {
                    if(s[i]=='a')
                        ax--;
                    if(s[i]=='e')
                        ex--;
                    if(s[i]=='i')
                        ix--;
                    if(s[i]=='o')
                        ox--;
                    if(s[i]=='u')
                        ux--;
                    i++;
                }
            }
            else if(s[j]=='e')
            {
                while(ix>0 || ox>0 || ux>0)
                {
                    if(s[i]=='a')
                        ax--;
                    if(s[i]=='e')
                        ex--;
                    if(s[i]=='i')
                        ix--;
                    if(s[i]=='o')
                        ox--;
                    if(s[i]=='u')
                        ux--;
                    i++;
                }
            
            }
            else if(s[j]=='i')
            {
                while(ox>0 || ux>0)
                {
                    if(s[i]=='a')
                        ax--;
                    if(s[i]=='e')
                        ex--;
                    if(s[i]=='i')
                        ix--;
                    if(s[i]=='o')
                        ox--;
                    if(s[i]=='u')
                        ux--;
                    i++;
                }
            
            }
            else if(s[j]=='o')
            {
                while(ux>0)
                {
                    if(s[i]=='a')
                        ax--;
                    if(s[i]=='e')
                        ex--;
                    if(s[i]=='i')
                        ix--;
                    if(s[i]=='o')
                        ox--;
                    if(s[i]=='u')
                        ux--;
                    i++;
                }
            
            }
            if(ax>0 && ex>0 && ix>0 && ox>0 && ux>0)
                res=max(res,j-i+1);
            j++;
            
        }
        return res;
        
    }
};