class Solution {
public:
    vector<string> ans;
    void f(int i,string& s,unordered_set<string>& hsh,string x)
    {
        if(i==s.size())
        {
            ans.push_back(x);
            return;
        }
        string str="";
        for(int idx=i;idx<s.size();idx++)
        {
           str+=s[idx];
           if(hsh.find(str)!=hsh.end())
           {
               if(i==0)
                   f(idx+1,s,hsh,str);
               else
                   f(idx+1,s,hsh,x+' '+str);
           }
        }
            
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
      unordered_set<string> hsh;
      for(auto x: wordDict)
          hsh.insert(x);
      ans.clear();
      f(0,s,hsh,"");
      return ans;
    }
};