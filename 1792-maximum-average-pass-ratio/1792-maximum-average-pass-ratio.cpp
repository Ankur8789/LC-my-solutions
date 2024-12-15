class Solution {
public:
    typedef long double ld;
    double maxAverageRatio(vector<vector<int>>& cl, int es) {
        ld ans=0.0;
        multiset<pair<ld,pair<int,int>>> ms;
        // rev is how much more you are getting from this .. as in total sum 
        for(auto x: cl){
            ld rev=ld(x[0]+1)/ld(x[1]+1)-ld(x[0])/ld(x[1]);
            ms.insert({rev,{x[0],x[1]}});
        }
        while(es--){
            auto fr=*ms.rbegin();
            ms.erase(--ms.end());
            auto x=fr.second.first,y=fr.second.second;
            x+=1;y+=1;
            ld rev=ld(x+1)/ld(y+1)-ld(x)/ld(y);
            ms.insert({rev,{x,y}});
        }
        for(auto x: ms){
            ans+=ld(x.second.first)/ld(x.second.second);
        }
        ans/=ld(ms.size());
        return ans;
    }
};