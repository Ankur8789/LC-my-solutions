class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> a(26);bool ans=false;
        vector<int> b(26);
         for(int i=0;i<s1.length();i++)
          a[int(s1[i])-'a']++;
        int i=0,j=0;
        while(j<s2.length())
        {
            b[int(s2[j])-'a']++;
            if(j-i+1<s1.length())
                j++;
            else if(j-i+1==s1.length())
            {
                 if(a==b)
                 ans=true;
                 b[int(s2[i])-'a']--;
                 i++;j++;
                if(ans==true)
                    break;
                     
            }
        }
        return ans;
    }
};