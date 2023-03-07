class Solution {
public:
    vector<string> ans;
    void f(int i,string s,unordered_set<string>& st,string& str)
    {
        if(i==s.length())
        {
            ans.push_back(str);
            return ;
        }
        string temp="";
        if(str.size()!=0)
        str+=' ';
        int cnt=0;
        
        for(int idx=i;idx<s.size();idx++)
        {
            temp+=s[idx];
            str+=s[idx];
            //cout<<str<<endl;
            cnt++;
            if(st.find(temp)==st.end())
                continue;
            //str+=' ';
            f(idx+1,s,st,str);
           
        }
        for(int j=0;j<=cnt;j++)
        str.pop_back();
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> st;
        for(auto t:wordDict)
            st.insert(t);
        string str="";
        f(0,s,st,str);
        return ans;
        
    }
};