class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        stack<pair<char,int>> st;
        map<int ,int> vis;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]==')' || s[i]=='(')
            {
                if(st.size()==0)
                    st.push({s[i],i});
                else
                {
                    if(s[i]==')')
                    {
                       if(st.top().first=='(')
                       {
                           vis[i]=1;
                           vis[st.top().second]=1;
                           st.pop();
                       }
                       else
                           st.push({s[i],i}); 
                    }
                    else
                    {
                       st.push({s[i],i});  
                    }
                }
            }
            else
                continue;
        }
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(s[i]==')' || s[i]=='(')
            {
                if(vis.find(i)!=vis.end())
                    ans+=s[i];
            }
            else
                ans+=s[i];
        }
        return ans;
    }
};