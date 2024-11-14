class Solution {
public:
    bool check(int mid,vector<int>& qty,int n){
       int cnt=0;
        for(auto x:qty){
            if(x<=mid)
                cnt++;
            else{
                int val=x;
                while(val>0){
                    val-=mid;
                    cnt++;
                }
            }
        }
        return cnt<=n;
    }
    int minimizedMaximum(int n, vector<int>& qty) {
        int l=1,r=*max_element(begin(qty),end(qty)),ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,qty,n)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};