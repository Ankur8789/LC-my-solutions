class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        int fin=0;
        for(auto t: nums)fin^=t;
        int cnt=0;
        for(int i=0;i<32;i++)
        {
            if(((fin>>i)&1)!=((k>>i)&1))
                cnt++;
        }
        return cnt;
        
    }
};