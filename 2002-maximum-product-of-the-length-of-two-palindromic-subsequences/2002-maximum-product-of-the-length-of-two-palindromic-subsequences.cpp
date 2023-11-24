class Solution {
public:
    int maxProduct(string s) 
    {
        int n=s.size();
        map<int,int> mp;
        for(int i=0;i<(1<<n);i++)
        {
           string tem="";
            for(int j=0;j<n;j++)
            {
                if((i>>j)&1)tem+=s[j];
            }
            string x=tem;
            string y=tem;
            reverse(y.begin(),y.end());
            if(x==y)
                mp[i]=x.size();
        }
        int res=0;
        for(auto x: mp)
        {
            for(auto y: mp)
            {
                if((x.first & y.first)==0)
                {
                    res=max(res,x.second*y.second);
                }
            }
        }
        return res;
    }
};