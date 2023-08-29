class Solution {
public:
    typedef long long ll;
    int bestClosingTime(string c) 
    { 
        int ny=0;
        for(int i=0;i<c.length();i++)
        {
            if(c[i]=='Y')
                ny++;
        }
        
        int temp=ny;
        if(ny==0)
            return 0;
        ll ans=0;
        for(int i=0;i<c.length();i++)
        {
            if(c[i]=='Y')
                ny--;
            else
                ny++;
            if(temp>ny)
            {
                ans=i+1;
                temp=ny;
            }
        }
        return ans;
    }
};