class Solution {
public:
    bool closeStrings(string a, string b) 
    {
       vector<int> fre1(26),fre2(26);
       for(auto t: a)
           fre1[t-'a']++;
       for(auto t: b)
           fre2[t-'a']++;
       for(int i=0;i<26;i++)
       {
           auto&x=fre1[i];
           auto&y=fre2[i];
           if((x>0 && y==0) || (y>0 && x==0))
               return false;
       }
       sort(begin(fre1),end(fre1));
       sort(begin(fre2),end(fre2));
       return fre1==fre2;
    }
};