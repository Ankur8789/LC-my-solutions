#define SORT(A) sort(A.begin(), A.end());
class Solution {
public:
    int minGroups(vector<vector<int>>& inv) {
        vector<int> arr,dep;
        for(auto x: inv){
            arr.push_back(x[0]);
            dep.push_back(x[1]);
        }
        SORT(arr);
        SORT(dep);
        int i=0,j=0,n=inv.size();
        int cnt=0,res=0;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            res=max(res,cnt);
        }
        return res;
    }
};