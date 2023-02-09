class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        vector<pair<int,int>> vp;
        for(int i=0;i<arr.size();i++)
        {
            int diff=abs(arr[i]-x);
            vp.push_back({diff,arr[i]});
        }
        sort(vp.begin(),vp.end());
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(vp[i].second);
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};