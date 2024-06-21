class Solution {
public:
    int maxSatisfied(vector<int>& cus, vector<int>& gr, int k) 
    {
        int n= cus.size();
        vector<int> pref(n),suff(n);
        if(gr[0]==0)
            pref[0]=cus[0];
        if(gr[n-1]==0)
            suff[n-1]=cus[n-1];
        for(int i=1;i<n-1;i++)
        {
            pref[i]+=pref[i-1];
            pref[i]+=(gr[i]==0)?cus[i]:0;
        }
        for(int i=n-2;i>=0;i--)
        {
            suff[i]+=suff[i+1];
            suff[i]+=(gr[i]==0)?cus[i]:0;
        }
        int on=0,zr=0;
        int ps=0;
        vector<int> sum;
        for(auto x: cus)
        {
            ps+=x;
            sum.push_back(ps);
        }
        int maxi=0;
        for(int i=0;i+k-1<n;i++)
        {
            int tmp=0;
            if(i-1>=0)
                tmp+=pref[i-1];
            if(i+k<n)
                tmp+=suff[i+k];
            tmp+=sum[i+k-1];
            if(i-1>=0)
                tmp-=sum[i-1];
            maxi=max(maxi,tmp);
            // cout<<i<<" "<<tmp<<endl;
              
        }
        return maxi;
    }
};