class Solution {
public:
    vector<string> ans;
    map<int,vector<char>> mp;
    void f(string& digits,int i,string& s)
    {
        // cout<<s<<endl;
        if(i==digits.size())
        {
          ans.push_back(s);
            return;
        }
        for(int idx=0;idx<mp[digits[i]-'0'].size();idx++)
        {
            s+=mp[digits[i]-'0'][idx];
            f(digits,i+1,s);
            s.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) 
    {
        if(digits.size()==0)
            return ans;
        mp[2]={'a','b','c'};
        mp[3]={'d','e','f'};
        mp[4]={'g','h','i'};
        mp[5]={'j','k','l'};
        mp[6]={'m','n','o'};
        mp[7]={'p','q','r','s'};
        mp[8]={'t','u','v'};
        mp[9]={'w','x','y','z'};
        // mp[2]={'a','b','c'};
        string s="";
        f(digits,0,s);
        if(digits.size()==0)
            return ans;
        if(ans.size()==0 && s.size())
            ans.push_back("");
        return ans;
    }
};