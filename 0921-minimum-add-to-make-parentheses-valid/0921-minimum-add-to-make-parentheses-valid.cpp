class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(auto x: s){
            if(st.size()==0)
                st.push(x);
            else{
                if(x==')'){
                    if(st.top()=='(')
                        st.pop();
                    else
                        st.push(x);
                }
                else{
                    st.push(x);
                }
            }
        }
        return st.size();
    }
};