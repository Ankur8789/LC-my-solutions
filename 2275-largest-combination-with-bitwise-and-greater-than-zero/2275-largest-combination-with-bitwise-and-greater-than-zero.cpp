class Solution {
public:
    int largestCombination(vector<int>& cd)
    {
        vector<int> msk(32);
        for(auto t: cd)
        {
            int v=t;
            for(int i=0;i<32;i++)
            {
                if((v>>i)&1==1)
                {
                    msk[i]++;
                }
            }
        }
        int mx=0;
        for(int i=0;i<32;i++)
        {
            if(msk[i]>mx)
                mx=msk[i];
        }
        return mx;
    }
};