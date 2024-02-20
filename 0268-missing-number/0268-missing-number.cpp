class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int res=0;
        for(int i=0;i<=nums.size();i++)
            res^=i;
        for(auto t: nums)
            res^=t;
        if(res==0)
        {
            bool found =false;
            for(auto t: nums)
                found|=(t==0);
            if(found)
                return nums.size();
            else
                return 0;
        }
        else
            return res;
    }
};