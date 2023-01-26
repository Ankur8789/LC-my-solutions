class Solution {
public:
    typedef long long ll;
    vector<pair<ll,double>> adj[10001];
    double pb[10001];
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& sp, int start, int end) 
    {
        for(ll i=0;i<sp.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],sp[i]});
            adj[edges[i][1]].push_back({edges[i][0],sp[i]});
        }
        pb[start]=1;
        multiset<pair<double,ll>> ms;
        ms.insert({1,start});
        while(ms.size()>0)
        {
            pair<double,ll> p=*ms.rbegin();
            auto it=ms.end();
            it--;
            ms.erase(it);
            double x=p.first;
            ll y=p.second;
            
            for(auto t: adj[y])
            {
                ll a=t.first;
                double b=t.second;
                if(double(pb[a])<double(x)*double(b))
                {
                    pb[a]=double(x)*double(b);
                    ms.insert({pb[a],a});
                }
            }
        }
        
            return pb[end];
    }
};