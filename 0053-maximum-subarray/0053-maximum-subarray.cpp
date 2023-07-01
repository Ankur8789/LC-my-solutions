class Solution {
public:
    int maxSubArray(vector<int>& v) 
    {
        int i=0,j=0,res=-1e9;
        int sum=0;
        int n=v.size();
        while(j<n)
        {
            sum+=v[j];
            res=max(res,sum);
            while(sum<0)
            {
                sum-=v[i];
                i++;
            }
            // res=max(res,sum);
            j++;
        }
        return res;
    }
};