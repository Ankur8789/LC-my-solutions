class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        int n=p.size();
        stack<int> st;
        vector<int> v(n);
        for(int i=n-1;i>=0;i--){
            while(st.size() && st.top()>p[i])
                st.pop();
            if(st.size()){
                v[i]=st.top();
            }
            st.push(p[i]);
        }
        for(int i=0;i<n;i++)
            p[i]-=v[i];
        return p;
    }
};