class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) 
    {
        queue<int> q;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            int parity=(q.size()&1);
            if(parity)
                nums[i]^=1;
            if(nums[i]==0)
            {
                if(i+k-1<nums.size())
                {
                   q.push(i+k-1);
                   cnt++;
                }
                else
                    return -1;
            }
            while(q.size()>0 && q.front()<=i)
                q.pop();
        }
        return cnt;
    }
};