class Solution {
public:
    bool check(int val,vector<int>& bd, int m, int k)
    {
       int cnt=0,res=0;
       for(auto x: bd)
       {
          if(x>val)
              res=0;
          else
              res++;
          if(res==k)
              cnt++,res=0;
       }
       return cnt>=m;
    }
    int minDays(vector<int>& bd, int m, int k) 
    {
       int l=1,r=*max_element(begin(bd),end(bd));
       
       int ans=-1;
       while(l<=r)
       {
           int mid=(l+r)/2;
           if(check(mid,bd,m,k))
             ans=mid,r=mid-1;
           else
               l=mid+1;
       }
       return ans;
    }
};