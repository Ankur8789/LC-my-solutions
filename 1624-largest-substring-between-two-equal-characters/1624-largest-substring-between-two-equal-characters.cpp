class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) 
    {
        int len=-1;
        unordered_map<char,vector<int>> fr;
        for(int i=0;i<s.size();i++)
            fr[s[i]].push_back(i);
        for(auto t: fr)
        {
            if(t.second.size()==1)
                continue;
            vector<int> hex=t.second;
            int m=hex.size();
            len=max(len,hex[m-1]-hex[0]-1);
        }
        return len;
    }
};