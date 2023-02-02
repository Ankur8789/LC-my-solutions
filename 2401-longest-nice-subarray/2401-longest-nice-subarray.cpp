class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) 
    {
        vector<int> msk(32);
        int i=0,j=0,n=nums.size(),res=INT_MIN;
        while(j<n)
        {
            int v=nums[j];
            for(int k=0;k<32;k++)
            {
                if((v>>k)&1)
                    msk[k]++;
            }
            while(1)
            {
                bool flg=false;
                for(int k=0;k<32;k++)
                {
                    if(msk[k]>1)
                       flg=true;
                }
                if(!flg)
                    break;
                int u=nums[i];
                for(int k=0;k<32;k++)
                {
                   if((u>>k)&1)
                       msk[k]--;
                }
                 i++;
            }
            res=max(res,j-i+1);
            j++;
            
        }
        return res;
    }
};