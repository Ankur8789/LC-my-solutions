class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        int i=0,j=0,len=0,cost=0;
        int n=s.size();
        while(j<n)
        {
            cost+=abs(s[j]-t[j]);
            while(cost>maxCost)
            {
                cost-=abs(s[i]-t[i]);
                i++;
            }
            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};