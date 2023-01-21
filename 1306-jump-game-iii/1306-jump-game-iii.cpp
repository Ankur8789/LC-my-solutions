class Solution {
public:
    bool canReach(vector<int>& arr, int start) 
    {
       queue<int> q;
       q.push(start);
        int n=arr.size();
        vector<int> vis(n);
       while(q.size()>0)
       {
           int x=q.front();
           q.pop();
           vis[x]=1;
           if(arr[x]==0)
               return true;
           if(x+arr[x]<n && vis[x+arr[x]]==0)
               q.push(x+arr[x]);
           if(x-arr[x]>=0 && vis[x-arr[x]]==0)
               q.push(x-arr[x]);
       }
        return false;
    }
};