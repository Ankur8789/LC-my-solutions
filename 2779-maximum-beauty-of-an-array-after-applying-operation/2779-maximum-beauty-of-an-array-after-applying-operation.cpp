class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> fre(300005);
        for(auto x: nums){
            int ri=x+k+100000,le=x+100000-k;
            fre[le]+=1;
            fre[ri+1]-=1;
        }
        for(int i=1;i<fre.size();i++)
            fre[i]+=fre[i-1];
        int maxi=0;
        for(auto x: fre)
            maxi=max(maxi,x);
        return maxi;
    }
};