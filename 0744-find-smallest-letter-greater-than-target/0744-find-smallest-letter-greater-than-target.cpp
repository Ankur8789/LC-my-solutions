class Solution {
public:
    char nextGreatestLetter(vector<char>& lt, char tg)
    {
       int l=0,r=lt.size()-1;
        char ans=lt[0];
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(lt[mid]>tg)
            {
                ans=lt[mid];
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};