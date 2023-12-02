class Solution {
public:
    int countCharacters(vector<string>& words, string chars)
    {
        vector<int> fre(26);
        for(auto t: chars)
            fre[t-'a']++;
        int ans=0;
        for(auto t: words)
        {
            vector<int> tmp(26);
            for(auto x:t)
                tmp[x-'a']++;
            bool ok=true;
            for(int i=0;i<26;i++)
            {
                if(tmp[i]>fre[i])
                    ok=false;
            }
            if(ok)
                ans+=t.size();
        }
        return ans;
    }
};