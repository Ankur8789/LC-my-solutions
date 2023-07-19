class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n=height.size();
        vector<int> left(n),right(n);
        stack<int> st;
        right[n-1]=0;
        right[0]=0;
        left[0]=0;
        left[n-1]=0;
        st.push(height[n-1]);
        for(int i=n-2;i>0;i--)
        {
            while(st.size()>0 && st.top()<height[i])
                st.pop();
            if(st.size()==0)
            {
                right[i]=0;
                st.push(height[i]);
            }
            else
            {
                right[i]=st.top();
            }
        }
        while(st.size())
            st.pop();
        st.push(height[0]);
        for(int i=1;i<n-1;i++)
        {
            while(st.size()>0 && st.top()<height[i])
                st.pop();
            if(st.size()==0)
            {
                left[i]=0;
                st.push(height[i]);
            }
            else
                left[i]=st.top();
        }
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            if(min(left[i],right[i])!=0)
                ans+=min(left[i],right[i])-height[i];
        }
        return ans;
        
    }
};