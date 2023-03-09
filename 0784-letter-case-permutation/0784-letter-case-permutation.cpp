class Solution {
public:
    void helper( vector<string>&ans,string s,int idx,string& temp){
        if(idx==s.length())
        {
            ans.push_back(temp);
            return;
            
        }
        if(s[idx]=='1'||s[idx]=='2'||s[idx]=='3'||s[idx]=='4'||s[idx]=='5'||s[idx]=='6'||s[idx]=='7'||s[idx]=='8'||s[idx]=='9'||s[idx]=='0')
        {  temp+=s[idx];
            helper(ans,s,idx+1,temp);
           temp.pop_back();
            return;
        }
        else{
        char c1=toupper(s[idx]);
        char c2=tolower(s[idx]);
            temp+=c1;
        helper(ans,s,idx+1,temp);
            temp.pop_back();
            temp+=c2;
        helper(ans,s,idx+1,temp);
             temp.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        string temp;
        helper(ans,s,0,temp);
        return ans;
        
    }
};