class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) 
    {
        sort(begin(arr),end(arr));
        arr[0]=1;
        int n=arr.size();
        for(int i=1;i<n;i++)
        {
            if(abs(arr[i]-arr[i-1])<=1)
                continue;
            else
            {
                arr[i]=arr[i-1]+1;
            }
        }
        int maxi=*max_element(begin(arr),end(arr));
        return maxi;
    }
};