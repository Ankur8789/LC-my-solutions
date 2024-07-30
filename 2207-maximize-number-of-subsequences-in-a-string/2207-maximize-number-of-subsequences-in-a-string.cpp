class Solution {
public:
    typedef long long ll;
    long long maximumSubsequenceCount(string text, string p) {
        ll ans=0;
        ll n=text.size();
        if(p[0]==p[1]){
            ll cnt=0;
            for(auto x: text)
                cnt+=(x==p[0]);
            cnt+=1;
            ans=(cnt*(cnt-1))/2;  
        }
        else{
            ll on=0,tw=0;
            for(auto x: text){
                if(x==p[0])on++;
                else if(x==p[1]) tw++,ans+=on;
            }
            ll res=ans;
            ll curon=0,curtw=0;
            for(ll i=0;i<n-1;i++){
                if(text[i]==p[0])curon++;
                else if(text[i]==p[1])curtw++;
                res=max(res,tw-curtw+ans);
                res=max(res,curon+ans); 
            }
            res=max(res,tw+ans);
            res=max(res,on+ans);
            ans=res;
        }
        return ans;
    }
};