class Solution {
public:
    bool check(int mid,vector<int>& pref,vector<int>& suff,vector<int>& arr){
        // removing i to j
        int i=0,j=0,n=arr.size();
        while(j<n){
            if(j-i+1<mid)
                j++;
            else if(j-i+1==mid){
                int cnt=0;
                bool ok=true;
                if(i>0)
                    cnt+=pref[i-1];
                if(j+1<n)
                    cnt+=suff[j+1];
                if(i-1>=0 && j+1<n){
                    if(arr[i-1]>arr[j+1])
                        ok=false;
                }
                // cout<<i<<" "<<j<<endl;
                if(cnt==n-mid && ok)
                    return 1;
                i++;
                j++;
            }
        }
        return 0;
    }
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        vector<int> pref(n),suff(n);
        pref[0]=1,suff[n-1]=1;
        for(int i=1;i<n;i++){
            if(arr[i]>=arr[i-1])
                pref[i]=pref[i-1]+1;
            else
                pref[i]=1;
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]<=arr[i+1])
                suff[i]=suff[i+1]+1;
            else
                suff[i]=1;
        }
        if(pref[n-1]==n )
            return 0;
        int l=1,r=n-1,ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,pref,suff,arr)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
            // cout<<check(7,pref,suff,arr)<<endl;
        return ans;
    }
};