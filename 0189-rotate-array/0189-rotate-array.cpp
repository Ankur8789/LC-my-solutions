class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
       // if(nums.size()==1)
       //     return;
       vector<int> temp=nums;
       for(auto t: nums)
           temp.push_back(t);
        int n=temp.size();
        int i=temp.size()-1;
        int j=i;
        k%=nums.size();
        while(i>=0)
        {
            if(abs(j-i)+1<nums.size())
                i--;
            else if(abs(i-j)+1==nums.size())
            {
                if(k==0)
                    break;
                k--;
                i--;
                j--;
            }
        }
        nums.clear();
        for(int idx=i;idx<=j;idx++)nums.push_back(temp[idx]);
        
    }
};