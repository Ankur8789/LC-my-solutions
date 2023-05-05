class Solution {
public:
    bool f(char ch)
    {
       if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
           return true;
        return false;
    }
    int maxVowels(string s, int k) 
    {
        int cc=0,res=0;
        int i=0,j=0,n=s.length();
        while(j<n)
        {
            if(f(s[j]))
                cc++;
            if(j-i+1<k)
                j++;
            else if(j-i+1==k)
            {
                res=max(res,cc);
                if(f(s[i]))
                    cc--;
                i++;
                j++;
            }
        }
        return res;
    }
};