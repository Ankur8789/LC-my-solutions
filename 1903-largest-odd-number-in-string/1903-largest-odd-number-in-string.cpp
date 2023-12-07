class Solution {
public:
    string largestOddNumber(string num)
    {
        int n = num.size();
        int k ;
        for(int i=0;i<n;i++)
        {
            int k = (num[n-1-i]-'0')%2;
            if(k==1)
            {
                return num.substr(0,n-i);
            }
        }
        return ""; 
    }
};