class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) 
    {
        int ans=0;
        for(auto t: left)
            ans=max(ans,abs(0-t));
        for(auto t: right)
            ans=max(ans,abs(n-t));
        return ans;
    }
};