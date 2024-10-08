class Solution {
public:
    int minSwaps(string s) 
    {
        int ans=0;
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            //st.push(s[i]);
            if(s[i]==']')
            {
                if(st.size()>0)
                    st.pop();
                else
                    ans++;
            }
            else
                st.push(s[i]);
        }
        return (ans+1)/2;
        
    }
};