class Solution {
    string f(int n) 
    {
        string ret(1, 'A' + (n % 26));
        n /= 26;
        if(n > 0)
            ret += f(n-1);
        return ret;
    }
   public:
    string convertToTitle(int n) 
    {
        string r = f(n-1);
        string ret(r.rbegin(), r.rend());
        return ret;
    }
};