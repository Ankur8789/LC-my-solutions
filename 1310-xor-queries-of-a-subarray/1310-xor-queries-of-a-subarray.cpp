class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> pref(n);
        pref[0]=arr[0];
        for(int i=1;i<n;i++)
            pref[i]=(pref[i-1] xor arr[i]);
        vector<int> ans;
        for(auto x: queries){
            int u=x[0],v=x[1];
            int val=pref[v];
            if(u>0)
                val^=pref[u-1];
            ans.push_back(val);
        }
        return ans;
    }
};