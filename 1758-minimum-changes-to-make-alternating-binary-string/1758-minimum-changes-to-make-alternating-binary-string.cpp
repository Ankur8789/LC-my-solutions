class Solution {
public:
    int minOperations(string s) 
    {
        int n=s.size();
        string s1="",s2="";
        int pre=1;
        for(int i=0;i<n;i++)
        {
            if(pre==1)
                s1+='1',s2+='0';
            else
                s1+='0',s2+='1';
            pre^=1;
        }
        int c1=0,c2=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=s1[i])
                c1++;
            if(s[i]!=s2[i])
                c2++;
        }
        return min(c1,c2);
    }
};