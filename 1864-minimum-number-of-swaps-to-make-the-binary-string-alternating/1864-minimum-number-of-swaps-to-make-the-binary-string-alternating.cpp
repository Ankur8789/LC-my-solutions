class Solution {
public:
    int minSwaps(string s) 
    {
        int n=s.size();
        int on=0,zr=0;
        for(auto t: s)
        {
            if(t=='1')
                on++;
            else
                zr++;
        }
        if(abs(on-zr)>1)
            return -1;
        string s1="1";
        string s2="0";
        int tem=1;
        while(n>1)
        {
            if(tem)
            {
                s1+='0';
                s2+='1';
            }
            else
            {
                s1+='1';
                s2+='0';
            }
            n--;
            tem^=1;
        }
         int cc1=0,cc2=0;
         for(int i=0;i<s.size();i++)
         {
             if(s1[i]!=s[i])cc1++;
             if(s2[i]!=s[i])cc2++;
         }
        if(cc1&1 && cc2&1)
            return -1;
        if(!(cc1&1) && !(cc2&1))
             return min(cc1/2,cc2/2);
        else if(cc1&1)
            return cc2/2;
        else
            return cc1/2;
    }
};