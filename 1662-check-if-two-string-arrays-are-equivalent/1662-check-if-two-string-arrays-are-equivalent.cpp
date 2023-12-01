class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2)
    {
       string s1="",s2="";
       for(auto t: word1)s1+=t;
       for(auto t: word2)s2+=t;
       return s1==s2;
    }
};