class Solution {
public:
    const int mod=1e9+7;
    typedef long long ll;
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) 
    {
       sort(hc.begin(),hc.end());
       sort(vc.begin(),vc.end());
       ll hmax=hc[0];
       ll vmax=vc[0];
       for(int i=0;i<hc.size()-1;i++)
           hmax=max(hmax,1LL*(hc[i+1]-hc[i]));
       for(int i=0;i<vc.size()-1;i++)
           vmax=max(vmax,1LL*(vc[i+1]-vc[i]));
       hmax=max(hmax,1LL*(h-hc[hc.size()-1]));
       vmax=max(vmax,1LL*(w-vc[vc.size()-1]));
       return (hmax*vmax)%mod;
    }
};