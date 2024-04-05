class Solution {
public:
    string makeGood(string s) 
    {  
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(int(s[i])>=65 && int(s[i])<=97)
            {
                if(st.size()>0 && int(st.top())>=97)
                {
                    if(int(st.top())-97==int(s[i])-65)
                    {
                           st.pop();
                        continue;
                    }
                }
            }
            if(int(s[i])>=97 && int(s[i])<=122)
            {
                if(st.size()>0 && int(st.top())>=65)
                {
                    if(int(st.top())-65==int(s[i])-97)
                    {
                        st.pop();
                        continue;
                    }
                }
            }
            st.push(s[i]);
        }
        string str;
        while(st.size()>0)
        {
            str+=st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};