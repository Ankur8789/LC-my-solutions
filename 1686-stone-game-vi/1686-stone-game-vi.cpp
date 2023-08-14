class Solution {
public:
    int stoneGameVI(vector<int>& av, vector<int>& bv) 
    {
        vector<vector<int>> vp;
        for(int i=0;i<av.size();i++)
            vp.push_back({av[i]+bv[i],av[i],bv[i]});
        int bs=0,as=0;
        sort(vp.begin(),vp.end());
        reverse(vp.begin(),vp.end());
        for(int i=0;i<vp.size();i++)
        {
            if(i&1)
            {
                bs+=vp[i][0];
                bs-=vp[i][1];
            }
            else
            {
                as+=vp[i][0];
                as-=vp[i][2];
            }
        }
        if(as>bs)
            return 1;
        if(as==bs)
            return 0;
        return -1;
        
    }
};