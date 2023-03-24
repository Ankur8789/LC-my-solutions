class Solution {
public:
    int openLock(vector<string>& dd, string target) 
    {
        unordered_set<string> st;
        for(auto t: dd)
            st.insert(t);
        if(st.find("0000")!=st.end())
            return -1;
        queue<string> q;
        q.push("0000");
        int lv=0;
        while(q.size()>0)
        {
           int sz=q.size();
            while(sz--)
            {
                string s=q.front();
                if(s==target)
                    return lv;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    if(s[i]=='0' || s[i]=='9')
                    {
                        if(s[i]=='0')
                        {
                            s[i]='1';
                            if(st.find(s)==st.end())
                            {
                                cout<<s<<endl;
                                st.insert(s);
                                q.push(s);
                            }
                            s[i]='9';
                            if(st.find(s)==st.end())
                            {
                                cout<<s<<endl;
                                st.insert(s);
                                q.push(s);
                            }
                            s[i]='0';
                            
                        }
                        else
                        {
                            s[i]='0';
                            if(st.find(s)==st.end())
                            {
                                cout<<s<<endl;
                                st.insert(s);
                                q.push(s);
                            }
                            s[i]='8';
                            if(st.find(s)==st.end())
                            {
                                cout<<s<<endl;
                                st.insert(s);
                                q.push(s);
                            }
                            s[i]='9';
                        }
                    }
                    else
                    {
                        char pre=s[i];
                        char ch=pre;
                        s[i]=ch+1;
                        if(st.find(s)==st.end())
                        {
                            cout<<s<<endl;
                            q.push(s);
                            st.insert(s);
                        }
                        //ch=pre;
                        s[i]=ch-1;
                        if(st.find(s)==st.end())
                        {  cout<<s<<endl;
                            q.push(s);
                            st.insert(s);
                        }
                        s[i]=pre;
                    }
                }
            }
            lv++;
        }
        return -1;
    }
};