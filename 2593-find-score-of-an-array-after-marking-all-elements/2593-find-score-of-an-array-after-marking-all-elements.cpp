class Solution {
public:
    typedef long long ll;
    long long findScore(vector<int>& nums) {
        set<pair<int,int>> ms;
        for(int i=0;i<nums.size();i++){
            ms.insert({nums[i],i});
        }
        int n=nums.size();
        vector<int> vis(n);
        ll sum=0;
        while(ms.size()){
            auto x=*ms.begin();
            ms.erase(ms.begin());
            int idx=x.second,val=x.first;
            if(vis[idx])
                continue;
            sum+=val;
            vis[idx]=1;
            if(idx-1>=0)
                vis[idx-1]=1;
            if(idx+1<n)
                vis[idx+1]=1;
        }
        return sum;
    }
};