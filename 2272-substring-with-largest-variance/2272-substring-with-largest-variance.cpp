class Solution {
public:
    int largestVariance(string s)
    {
        int ans=0;
        unordered_map<char,int> mp;
        for(auto t: s)
            mp[t]++;
        for(char ch='a';ch<='z';ch++)
        {
            for(char p='a';p<='z';p++)
            {
                if(ch==p)
                    continue;
                if(mp.find(ch)==mp.end() || mp.find(p)==mp.end())
                    continue;
                int res=0;
                int cnt=0;
                map<char,int> cc;
                for(auto t: s)
                {
                    if(t==ch)
                        cnt++,cc[t]++;
                    if(t==p)
                        cnt--,cc[t]++;
                    
                    if(cc.size()==2)
                    res=max(res,cnt);
                    if(cnt<0)
                    {
                        cnt=0;cc.clear();
                    }
                }
                cc.clear();
                reverse(s.begin(),s.end());
                cnt=0;
                for(auto t: s)
                {
                    if(t==ch)
                        cnt++,cc[t]++;
                    if(t==p)
                        cnt--,cc[t]++;
                    
                    if(cc.size()==2)
                    res=max(res,cnt);
                    if(cnt<0)
                    {
                        cnt=0;cc.clear();
                    }
                }
                // cout<<ch<<" "<<p<<" "<<res<<" "<<cnt<<endl;
                ans=max(ans,res);
                reverse(s.begin(),s.end());
            }
        }
        return ans;
    }
};