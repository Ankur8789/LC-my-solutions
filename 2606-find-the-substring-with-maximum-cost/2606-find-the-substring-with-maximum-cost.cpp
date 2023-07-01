class Solution {
public:
    
    int maximumCostSubstring(string s, string chars, vector<int>& vals) 
    {
        unordered_map<char,int> mp;
        int n=vals.size();
        for(int i=0;i<n;i++)
            mp[chars[i]]=vals[i];
        int ans=0;
        int ps=0;
        for(auto t: s)
        {
            int val;
            if(mp.find(t)!=mp.end())
                val=mp[t];
            else
                val=t-'a'+1;
            ps+=val;
            ans=max(ps,ans);
            if(ps<0)
                ps=0;
        }
        return ans;
    }
};