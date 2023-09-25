class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        char res=s[0];
        for(int i=1;i<s.size();i++)
            res^=s[i];
        for(auto p: t)
            res^=p;
        return res;
    }
};