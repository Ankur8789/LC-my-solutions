class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        vector<int> left(n),right(n);
        left[0]=-1,right[n-1]=-1;
        stack<int> st;
        st.push(h[0]);
        for(int i=1;i<n;++i){
            while(st.size() && st.top()<h[i])
                st.pop();
            if(st.size()==0)
               { left[i]=-1,st.push(h[i]);}
            else
                left[i]=st.top();
            
        }
        while(st.size())
            st.pop();
        st.push(h[n-1]);
        for(int i=n-2;i>=0;i--){
            while(st.size() && st.top()<h[i])
                st.pop();
            if(st.size()==0)
                {right[i]=-1,st.push(h[i]);}
            else
                right[i]=st.top();
            
        }
        int tot=0;
        for(int i=0;i<n;i++){
            int mini=min(left[i],right[i]);
            if(mini==-1)
                continue;
            else 
                tot+=(mini-h[i]);
        }
        return tot;
    }
};