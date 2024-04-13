class Solution {
public:
    int largestRectangleArea(vector<int>& h) 
    {
       stack<int> st;
       int n = h.size();
       vector<int> left(n),right(n);
       for(int i = 0;i < n ;i++)
       {
           left[i]=i;
           while(st.size()>0 && h[st.top()]>=h[i])
                st.pop();
           if(st.size()==0)
               left[i] = -1;
           else
               left[i]=st.top();
           st.push(i);
       }
       while(st.size())
           st.pop();
       for(int i=n-1;i>=0;i--)
       {
           right[i] = i;
           while(st.size()>0 && h[st.top()]>=h[i])
               st.pop();
           if(st.size()==0)
               right[i]=n;
           else
               right[i] = st.top();
           st.push(i);
       }
       int maxi=0;
       for(int i=0;i<n;i++)
       {
           int dis = right[i] - left[i] - 1;
           // cout<<left[i]<<" "<<right[i]<<endl;
           maxi = max(maxi , dis*h[i]);
       }
      return maxi ;
    }
};