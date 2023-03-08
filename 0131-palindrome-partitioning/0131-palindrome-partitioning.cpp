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
        string st="";
     for(int idx=i;idx<s.length();idx++)
        {
            st+=s[idx];
           if(p(st))
           {
              temp.push_back(st);
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