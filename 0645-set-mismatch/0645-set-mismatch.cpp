class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> fre(n+1);
        for(auto t: nums)
            fre[t]+=1;
        int twi,miss;
        for(int i=1;i<=n;i++)
        {
            if(fre[i]==0)
                miss=i;
            if(fre[i]==2)
                twi=i;
        }
        return {twi,miss};
    }
};