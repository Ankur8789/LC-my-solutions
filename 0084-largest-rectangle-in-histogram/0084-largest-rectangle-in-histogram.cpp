class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        vector<int> left(n),right(n);
        left[0]=-1,right[n-1]=n;
        stack<int> st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(st.size()>0 && h[st.top()]>=h[i]){
                st.pop();
            }
            if(st.size()==0){
                left[i]=-1;
            }
            else{
                left[i]=st.top();
            }
            st.push(i);
        }
        while(st.size())
            st.pop();
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && h[st.top()]>=h[i]){
                st.pop();
            }
            if(st.size()==0){
                right[i]=n;
            }
            else{
                right[i]=st.top();
            }
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
          int l=left[i]+1,r=right[i]-1;
          int dis=r-l+1;
          ans=max(ans,h[i]*dis);
        }
        return ans;
    }
};