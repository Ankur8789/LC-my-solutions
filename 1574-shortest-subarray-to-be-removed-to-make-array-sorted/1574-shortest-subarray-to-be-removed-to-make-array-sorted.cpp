class Solution {
public:
    bool check(int mid, vector<int>& pref,vector<int>& suff,vector<int>& arr){
        int i = 0 ,j = 0, n = arr.size();
        while(j <  n){
            // cout << i << " " << j <<endl;
            if(j-i+1 < mid)
                j++;
            else if(j-i+1 == mid){
                // removing i to  j 
                int cnt = 0;
                if(i-1 >= 0)
                    cnt += pref[i-1];
                if(j+1 <= n-1)
                    cnt += suff[j+1];
                int rem = n - (j - i + 1);
                bool hex = true;
                if(i-1 >= 0 && j+1 <= n-1){
                    if(arr[i-1] > arr[j+1])
                        hex = false;
                }
                // cout<<i<<" "<<j<<" "<<cnt<<" "<<rem<<endl;
                if(cnt >= rem && hex){
                    return true;
                }
                i++;
                j++;
            }
        }
        return false;
    }
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        vector<int> pref(n),suff(n);
        pref[0] = 1 , suff[n-1] = 1;
        for(int i=1;i<n;i++){
            if(arr[i]>=arr[i-1])
                pref[i]=pref[i-1]+1;
            else
                pref[i]= 0;
        }
        for(int i=n-2;i>=0;i--){
            if(arr[i]<=arr[i+1])
                suff[i] = suff[i+1]+1;
            else
                suff[i] = 0;
        }
        if(pref[n-1] == n){
            return 0;
        }
        int l = 1,r = n-1,ans = n-1;
        while(l <= r){
            int mid = (l+r)/2;
            if(check(mid,pref,suff,arr)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        // cout << check(3,pref,suff,arr);
        return ans;
    }
};