class Solution {
public:
    int countPalindromicSubsequence(string s) 
    {
        unordered_set<string> st;
        int n=s.size();
        vector<int> pref(26),suff(26);
        for(int i=n-1;i>=0;i--)
            suff[s[i]-'a']++;
        for(int i=0;i<n;i++)
        {
            suff[s[i]-'a']--;
            for(int j=0;j<26;j++)
            {
                if(pref[j]>0 && suff[j]>0)
                {
                   string temp="";
                   temp+=char(j+'a');
                   temp+=s[i];
                   temp+=char(j+'a');
                   st.insert(temp);
                }
            }
            pref[s[i]-'a']++;
        }
        return st.size();
            
    }
};