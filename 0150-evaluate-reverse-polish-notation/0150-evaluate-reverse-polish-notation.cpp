class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> st;
        int res=0;
        for(auto t: tokens)
        {
            if(t=="*" || t=="+" || t=="-" || t=="/")
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                swap(a,b);
                if(t=="*")
                    a*=b;
                else if(t=="+")
                    a+=b;
                else if(t=="-")
                    a-=b;
                else
                    a/=b;
                st.push(a);
            }
            else
                st.push(stoi(t));
        }
        return st.top();
    }
};