class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> a(26);
        vector<int> b(26);
         for(int i=0;i<p.length();i++)
             a[int(p[i])-'a']++;
          vector<int> ans;
         int i=0,j=0;
        while(j<s.length())
        {
            b[int(s[j])-'a']++;
            if(j-i+1<p.length())
                j++;
            else if(j-i+1==p.length())
            {
                 if(a==b)
                     ans.push_back(i);
                  b[int(s[i])-'a']--;
                i++;j++;
            }
        }
        return ans;
    }
};