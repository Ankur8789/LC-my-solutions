class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int ta=0,tb=0;
        int cnta=0,cntb=0;
        for(auto x: s){
            if(x=='b')
                tb++;
            else
                ta++;
        }
        int ans=n;
        ans=min(ans,min(n-ta,n-tb));
        for(auto x: s){
            if(x=='a')
                cnta++;
            else
                cntb++;
            int res=cntb+ta-cnta;
            ans=min(ans,res);
        }
        return ans;
    }
};