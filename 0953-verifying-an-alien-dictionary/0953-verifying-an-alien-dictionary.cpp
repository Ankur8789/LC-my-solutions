class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) 
    {
        unordered_map<char,int> mp;
        for(int i=0;i<order.length();i++)
            mp[order[i]]=i;
        for(int i=0;i<words.size()-1;i++)
        {
            string s1=words[i];
            string s2=words[i+1];
            bool flag=false;
            for(int j=0;j<min(s1.length(),s2.length());j++)
            {
                if(s1[j]!=s2[j])
                {  flag=true;
                    if(mp[s1[j]]>mp[s2[j]])
                        return false;
                    break;
                }
                
            }
            if(!flag)
            {
                if(s1.length()>s2.length())
                    return false;
            }
        }
        return true;
    }
};