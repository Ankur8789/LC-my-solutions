class Solution {
public:
    bool validateStackSequences(vector<int>& ps, vector<int>& po) 
    {
        stack<int> st;
        int j=0;
        auto n=ps.size();
        for(int i=0;i<ps.size();i++)
        {
            st.push(ps[i]);
            while(j<n && st.size()>0 && st.top()==po[j])
            {
                st.pop();
                j++;
            }
        }
        if(j==n && st.size()==0)
            return true;
        return false;
        
    }
};