class Solution {
public:
    bool backspaceCompare(string s, string tt) 
    {
        string res1="",res2="";
        for(auto t: s)
        {
            if(t=='#')
            {
                if(res1.size()!=0)
                    res1.pop_back();
            }
            else
                res1+=t;
        }
        for(auto t:tt)
        {
            if(t=='#')
            {
                if(res2.size()!=0)
                    res2.pop_back();
            }
            else
                res2+=t;
        }
        return (res1==res2);
    }
};