class Solution {
public:
    string removeStars(string s) 
    {
        stack<char> st;
        for(auto t: s)
        {
           if(t=='*')
           {
               if(st.size()>0)
                   st.pop();
           }
            else
                st.push(t);
        }
        string ans="";
        while(st.size()>0)
        {
           ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    
    }
};