class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {
         string st=s+s;
         string stt=st.substr(1,st.size()-2);
         return stt.find(s)!=-1;
    }
};