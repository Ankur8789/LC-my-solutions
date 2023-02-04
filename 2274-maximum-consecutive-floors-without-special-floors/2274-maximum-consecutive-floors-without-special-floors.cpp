class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& sp) 
    {
        int ans=INT_MIN;
        sort(sp.begin(),sp.end());
        ans=max(ans,sp[0]-bottom);
        for(int i=0;i<sp.size()-1;i++)
        {
            ans=max(ans,sp[i+1]-sp[i]-1);
        }
        ans=max(ans,top-sp[sp.size()-1]);
        return ans;
    }
};