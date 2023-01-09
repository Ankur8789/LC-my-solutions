class Solution {
public:
    int ladderLength(string bg, string ed, vector<string>& wl)
    {
        set<string> s;
        for(auto t: wl)
            s.insert(t);
        if(s.find(ed)==s.end() || bg==ed)
            return 0;
        if(s.find(bg)!=s.end())
            s.erase(bg);
        queue<pair<string,int>> q;
        q.push({bg,1});
        //int cnt=1;
        while(q.size()>0)
        {
           string str=q.front().first;
            int x=q.front().second;
            q.pop();
            if(str==ed)
                        return x;
            for(int i=0;i<str.length();i++)
            {
                char org=str[i];
                for(char ch='a';ch<='z';ch++)
                {
                    str[i]=ch;
                    
                    if(s.find(str)!=s.end())
                    {
                        q.push({str,x+1});
                        s.erase(str);
                    }
                    
                }
                str[i]=org;
            }
        }
        return 0;
    }
};