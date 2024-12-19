class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
       int n=arr.size();
       int a[n];
       for(int i=0;i<n;i++)a[i]=i;
       int idx=0;
       set<int> st;
       int ans=0;
       for(int i=0;i<n;i++){
           // min == a[idx] && max == a[i] && idx-i+1 == st.size()
           st.insert(arr[i]);
           if(*st.begin()==a[idx] && *st.rbegin()==a[i] && i-idx+1==st.size()){
               ans++;
               st.clear();
               idx=i+1;
           }
       }
       return ans;
    }
};