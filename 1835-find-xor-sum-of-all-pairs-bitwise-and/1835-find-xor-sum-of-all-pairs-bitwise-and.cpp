class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) 
    {
        int ans1=0;
        for(auto t: arr1)
            ans1^=t;
        int ans2=0;
        for(auto t: arr2)
            ans2^=t;
        return ans1&ans2;
    }
};