class Solution {
public:
    char repeatedCharacter(string s) 
    {
        unordered_map<char,int> mp;
        for(auto t:s)
        {
            if(mp.find(t)!=mp.end())
                return t;
            mp[t]++;
        }
        return '#';
    }
};