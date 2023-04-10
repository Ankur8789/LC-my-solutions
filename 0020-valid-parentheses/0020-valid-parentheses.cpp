class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        for(auto t: s)
        {
            if(t=='}' && st.size()>0 && st.top()=='{')
                st.pop();
            else if(t==')' && st.size()>0 && st.top()=='(')
                st.pop();
            else if(t==']' && st.size()>0 && st.top()=='[')
                st.pop();
            else
                st.push(t);
        }
        return st.size()==0;
    }
};