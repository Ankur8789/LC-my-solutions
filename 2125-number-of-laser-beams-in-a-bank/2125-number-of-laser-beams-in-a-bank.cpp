class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {
        int n=bank.size();
        vector<int> fre;
        for(auto t: bank)
        {
           int cnt=0;
            for(auto x: t)
                cnt+=(x=='1');
            if(cnt>0)
                fre.push_back(cnt);
        }
        if(fre.size()<=1)
            return 0;
        int ans=0;
        for(int i=0;i<fre.size()-1;i++)
            ans+=fre[i]*fre[i+1];
        return ans;
    }
};