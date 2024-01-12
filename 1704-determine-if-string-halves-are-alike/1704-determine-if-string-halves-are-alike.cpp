class Solution {
public:
    bool halvesAreAlike(string s) 
    {
        set<char> st={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int cnt1=0,cnt2=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(st.find(s[i])!=st.end())
            {
                if(i<n/2)cnt1++;
                else cnt2++;
            }
        }
        return cnt1==cnt2;
    }
};