class Solution {
public:
    int minFlipsMonoIncr(string s) 
    {
        int zr=0,on=0;
        for(auto t: s)
        {
            if(t=='0')zr++;
            else on++;
        }
        int ans=INT_MAX;
        int zrc=0,onc=0;
        for(auto t: s)
        {
           if(t=='0')
           {
              ans=min(ans,onc+zr-zrc-1);
              ans=min(ans,1+onc+zr-zrc-1);
           }
            else
            {
                ans=min(ans,onc+zr-zrc);
                ans=min(ans,onc+1+zr-zrc);
            }
            if(t=='0')zrc++;
            else onc++;
        }
        return ans;
    }
};