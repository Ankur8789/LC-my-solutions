class Solution {
public:
    string maximumOddBinaryNumber(string s) 
    {
        int on=0;
        for(auto t: s)
            on+=(t=='1');
        int zr=s.size()-on;
        string ans="";
        while(on>1)
            ans+='1',on--;
        while(zr--)
            ans+='0';
        if(on)
            ans+='1';
        return ans;
    }
};