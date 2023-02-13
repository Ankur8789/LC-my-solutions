class Solution {
public:
    int ladderLength(string sw, string ew, vector<string>& wordList)
    {
        set<string> s;
        for(auto t:wordList)s.insert(t);
        if(s.find(ew)==s.end())
            return 0;
        queue<string> q;
        q.push(sw);
        s.erase(sw);
        int lvl=1;
        while(q.size()>0)
        {  
            int sz=q.size();
            while(sz--)
            {
                string temp=q.front();
                q.pop();
                for(int i=0;i<temp.size();i++)
                {
                    char prev=temp[i];
                    for(char ch='a';ch<='z';ch++)
                    {
                        temp[i]=ch;
                        if(temp==ew)
                            return lvl+1;
                        if(ch==prev)
                            continue;
                        if(s.find(temp)!=s.end())
                        {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                    temp[i]=prev;
                }
            }
            lvl++;
        }
        return 0;
    }
};