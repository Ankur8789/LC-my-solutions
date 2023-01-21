class Solution {
public:
    vector<string> ans;
    bool valid(string s)
    {
        if(s.size()>3 or s.size()==0)
            return false;

        if(s.size() and stoi(s)>255)
            return false;

        if(s.size()>1 and s[0]=='0')
            return false;

        return true;
    }

    void solve(string s, int ind, int dots, string temp)
    {
        if(dots==3){
            if(valid(s.substr(ind)))
                ans.push_back(temp+s.substr(ind));

            return;
        }

        for(int i=ind; i<s.size(); i++)
        {
            if(valid(s.substr(ind, i-ind+1)))
            {
                temp.push_back(s[i]);
                temp.push_back('.');
                solve(s, i+1, dots+1, temp);
                temp.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) 
    {
        string temp="";
        solve(s, 0, 0, temp);   
        return ans;  
    }
};