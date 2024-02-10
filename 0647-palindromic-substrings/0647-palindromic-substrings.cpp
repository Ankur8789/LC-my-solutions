class Solution {
public:
    int countSubstrings(string s) 
    {
    
        map<string,int> m;int count=0;
        for(int i=0;i<s.length();i++)
        {
            for(int j=0;j<=s.length()-i-1;j++)
            {
                string a=s.substr(i,j+1);
                string b=a;
                reverse(a.begin(),a.end());
                if(a==b)
                    count++;
            }
        }
        return count;
        
    }
};