
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& fl, vector<int>& ps) 
    {
       vector<int> ans;
       int n=fl.size();
        vector<int> st(n),et(n);
        for(int i=0;i<n;i++)
        {
            st[i]=fl[i][0];
            et[i]=fl[i][1];
        }
        sort(st.begin(),st.end());
        sort(et.begin(),et.end());
        for(int i=0;i<ps.size();i++)
        {
            int x=upper_bound(st.begin(),st.end(),ps[i])-st.begin();
            int y=lower_bound(et.begin(),et.end(),ps[i])-et.begin();
            ans.push_back(x-y);
        }
        return ans;
        
    }
};