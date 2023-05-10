class Solution {
public:
    int numSplits(string s) 
    {
       set<int> st;
       vector<int> ct,cs;
       for(auto t: s)
       {
           st.insert(t);
           ct.push_back(st.size());
       }
        st.clear();
        cs.resize(s.size());
       for(int i=s.length()-1;i>=0;i--)
       {
          
           cs[i]=st.size();
           st.insert(s[i]);
       }
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(ct[i]==cs[i])
                ans++;
        }
        return ans;
        
    }
};