class Solution {
public:
    int minLength(string s) 
    {
        stack<char>st;
        for(auto t: s)
        {
            if(st.size()==0)
            {
                st.push(t);
            }
            else
            {
                if(t=='B' && st.top()=='A')
                    st.pop();
                else if(t=='D'&& st.top()=='C')
                    st.pop();
                else
                    st.push(t); 
            }
        }
        return st.size();
    }
};