class Solution {
public:
    bool p(string s)
    {
        for (int i = 0; i < s.length() / 2; i++)
          {

             if (s[i] != s[s.length() - i - 1])
            return false;
        
          }
        return true;
    }
    void f(int i,vector<string>& temp,vector<vector<string>>& ans,string s,string str)
    {
        if(i==s.length())
        {
            ans.push_back(temp);
            return ;
        }
        if(i==s.length()-1)
        {
            if(p(s.substr(i)))
            {
               
                temp.push_back(s.substr(i));
                ans.push_back(temp);
                temp.pop_back();
                
            }
            return ;
        }
        for(int idx=i;idx<s.length();idx++)
        {
            if(p(s.substr(i,idx-i+1)))
            {
                temp.push_back(s.substr(i,idx-i+1));
                f(idx+1,temp,ans,s,str);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> temp;
        f(0,temp,ans,s,"");
        return ans;
    }
};