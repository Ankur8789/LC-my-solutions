class Solution {
public:
    int largestCombination(vector<int>& cd) {
        vector<int> fre(32);
        for(auto x: cd){
            for(int i=0;i<32;i++)
                fre[i] += ((x >> i)&1);
        }
        int maxi = 0;
        for(auto x : fre)
            maxi = max(maxi , x);
        return maxi;
    }
};