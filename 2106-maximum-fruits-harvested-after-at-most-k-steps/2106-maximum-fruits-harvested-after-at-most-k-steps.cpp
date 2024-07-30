class Solution {
public:
    const static int sz=2*(100000)+5;
    int pref[2000005];
    bool check(int val,int sp,int k){
        for(int i=0;i<sz && i<=k;i++){
            int fwd=i;
            int bwd=k-2*i;
            if(fwd<0 || bwd<0)
                break;
            int total=pref[sp+i];
            total-=pref[sp];
            int idx=max(0,sp-bwd);
            total+=pref[sp];
            if(idx>0)
                total-=pref[idx-1];
            if(total>=val)
               return 1;
        }
        for(int i=0;i<=k ;i++){
            int bidx=max(0,sp-i);
            int fidx=min(sz-1,sp+(k-2*i));
            if(fidx<0 || bidx<0)
                continue;
            int total=pref[fidx];
            total-=pref[sp];
            total+=pref[sp];
            if(bidx>0)
                total-=pref[bidx-1];
            if(total>=val)
                return 1;
        }
        return 0;
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int sp, int k) {
        
        for(int i=0;i<2000005;i++)
            pref[i]=0;
        for(auto x: fruits){
            int pos=x[0];
            int fr=x[1];
            pref[pos]+=fr;
        }
        for(int i=1;i<2000005;i++)
            pref[i]+=pref[i-1];
        int l=0,r=1e9;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,sp,k)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};