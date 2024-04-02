class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        if(s.size()!=t.size())
            return 0;
        map<char,int> idx1,idx2,fre1,fre2;
        for(int i=0;i<s.size();i++)
        {
           if(idx1.find(s[i])==idx1.end())
               idx1[s[i]]=i;
           fre1[s[i]]++;
           if(idx2.find(t[i])==idx2.end())
               idx2[t[i]]=i;
           fre2[t[i]]++;
           if(idx1[s[i]]!=idx2[t[i]] || fre1[s[i]]!=fre2[t[i]])
               return 0;
        }
        return 1;
    }
};