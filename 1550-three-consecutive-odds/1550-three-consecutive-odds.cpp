class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) 
    {
        if(arr.size()<3)
            return 0;
        for(auto& x: arr)
            x%=2;
        for(int i=0;i<=arr.size()-3;i++)
        {
            int temp=arr[i]+arr[i+1]+arr[i+2];
            if(temp==3)
                return 1;
        }
        return 0;
    }
};