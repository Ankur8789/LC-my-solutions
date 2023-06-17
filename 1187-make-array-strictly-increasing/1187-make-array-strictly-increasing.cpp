class Solution {
public:
    map<pair<int,int>,int> mp;
    int f(int i,int pre,vector<int>&arr1,vector<int>& arr2)
    {
        if(i==arr1.size())
            return 0;
        if(mp.find({i,pre})!=mp.end())
            return mp[{i,pre}];
        int ans=1e7;
        if(arr1[i]>pre)
        {
            ans=min(ans,f(i+1,arr1[i],arr1,arr2));
            int idx=lower_bound(arr2.begin(),arr2.end(),pre)-arr2.begin();
            if(idx<arr2.size())
            {
                if(arr2[idx]==pre)
                {
                    idx++;
                    if(idx<arr2.size())
                        ans=min(ans,1+f(i+1,arr2[idx],arr1,arr2));
                }
                else
                    ans=min(ans,1+f(i+1,arr2[idx],arr1,arr2));
            }
        }
        else
        {
            int idx=lower_bound(arr2.begin(),arr2.end(),pre)-arr2.begin();
            if(idx<arr2.size())
            {
                if(arr2[idx]==pre)
                {
                    idx++;
                    if(idx<arr2.size())
                        ans=min(ans,1+f(i+1,arr2[idx],arr1,arr2));
                }
                else
                    ans=min(ans,1+f(i+1,arr2[idx],arr1,arr2));
            }
        }
        return mp[{i,pre}]=ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2)
    {
        sort(arr2.begin(),arr2.end());
        vector<int> ax2;
        map<int,int> mp;
        for(auto t: arr2)
        {
            if(mp.find(t)!=mp.end())
                continue;
            ax2.push_back(t);
            mp[t]++;
        }
        sort(ax2.begin(),ax2.end());
        int ans=f(0,-1,arr1,ax2);
        if(ans==1e7)
            ans=-1;
        return ans;
    }
};