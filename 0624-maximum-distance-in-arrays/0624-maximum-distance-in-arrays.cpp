class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini=arrays[0][0];
        int maxi=arrays[0].back();
        int ans=-1e9;
        for(int i=1;i<arrays.size();i++){
            int d1=arrays[i].back()-mini;
            int d2=maxi-arrays[i][0];
            ans=max({ans,d1,d2});
            mini=min(mini,arrays[i][0]);
            maxi=max(maxi,arrays[i].back());
        }
        return ans;
    }
};