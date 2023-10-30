class Solution {
public:
    static bool cmp(pair<int,int>& a,pair<int,int>& b)
    {
        if(a.first==b.first)
            return a.second<b.second;
        else
            return a.first<b.first;
    }
    vector<int> sortByBits(vector<int>& arr) 
    {
        vector<pair<int,int>> vp;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            int val=arr[i];
            int cnt=0;
            while(val)
            {
                val=val&(val-1);
                cnt++;
            }
            vp.push_back({cnt,arr[i]});
        }
        sort(vp.begin(),vp.end(),cmp);
        vector<int> ans;
        for(auto t: vp)
            ans.push_back(t.second);
        return ans;
    }
};