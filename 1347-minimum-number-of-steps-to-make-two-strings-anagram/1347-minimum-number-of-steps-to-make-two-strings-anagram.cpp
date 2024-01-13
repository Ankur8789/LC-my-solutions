class Solution {
public:
    int minSteps(string s, string t)
    {
       vector<int> a(26);vector<int> b(26);
         for(int i=0;i<s.length();i++)
             a[int(s[i])-'a']++;
         for(int i=0;i<t.length();i++)
             b[int(t[i])-'a']++;
         int cnt=0;
        for(int i=0;i<26;i++)
        {
             if(a[i]>b[i])
                 cnt+=a[i]-b[i];
        }
        return cnt;
    }
};