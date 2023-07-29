class Solution {
public:
    vector<string> ans;
    void f(int i,int op,int n,string& s)
    {
        if(i==2*n)
        {
            if(op==0)
                ans.push_back(s);
            return;
        }
        if(op>0)
        {
            s+='(';
           f(i+1,op+1,n,s);
            s.pop_back();
            s+=')';
           f(i+1,op-1,n,s);
            s.pop_back();
        }
        else
        {
            s+='(';
           f(i+1,op+1,n,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        string s;
       f(0,0,n,s);
        return ans;
    }
};