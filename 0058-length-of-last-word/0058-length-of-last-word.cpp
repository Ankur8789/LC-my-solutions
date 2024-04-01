class Solution {
public:
    int lengthOfLastWord(string s)
    {
        vector<string> v;
        string str="";
        int i=0;
        while(i<s.size())
        {
            if(s[i]==' ')
            {
                if(str.size())
                v.push_back(str);
                str="";
            }
            else
                str+=s[i];
            i++;
        }
        if(str.size())
            v.push_back(str);
        return v.back().size();
    }
};