class Solution {
public:
    int partitionString(string s) 
    {
        set<char> st;
        int cc=0;
        for(auto t: s)
        {
            if(st.find(t)!=st.end())
            {
                cc++;
                st.clear();
                st.insert(t);
            }
            else
            {
                st.insert(t);
            }
        }
        if(st.size()>0)
            cc++;
        return cc;
    }
};