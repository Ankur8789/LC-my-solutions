class Solution {
public:
    string makeFancyString(string s) {
        stack<char> st;
        for(auto x : s){
            if(st.size() < 2)
                st.push(x);
            else{
                char a = st.top() ; st.pop();
                char b = st.top() ; st.pop();
                st.push(b);
                st.push(a);
                if(a != x || b != x)
                    st.push(x);
                
            }
        }
        string res = "";
        while(st.size())
            res += st.top() , st.pop();
        reverse(begin(res) , end(res));
        return res;
    }
};