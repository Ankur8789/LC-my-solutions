//these type of question are of contribution tech....
class Solution {
public:
    int uniqueLetterString(string s) 
    {
        vector<int> fre[26];
        for(int i=0;i<s.length();i++)
            fre[s[i]-'A'].push_back(i);
        int n=s.length();
        int ans=0;
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<fre[i].size();j++)
            {
                int pr,nx;
                if(j==0)
                    pr=fre[i][j]+1;
                else
                    pr=fre[i][j]-fre[i][j-1];
                if(j+1==fre[i].size())
                    nx=n-fre[i][j];
                else
                    nx=fre[i][j+1]-fre[i][j];
                ans+=(pr*nx);
            }
        }
        return ans;
            
    }
};
