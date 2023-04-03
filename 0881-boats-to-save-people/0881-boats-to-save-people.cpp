class Solution {
public:
    bool check(int mid,vector<int>& pe, int lt)
    {
        int i=0,j=pe.size()-1;
        int cc=0;
        while(i<=j)
        {
            if(i==j)
            {
               cc++;
               break;
            }
            if(pe[j]+pe[i]>lt)
            {
                cc++;
                j--;
            }
            else
            {
                cc++;
                i++;
                j--;
            }
            
        }
        return cc<=mid;
    }
    int numRescueBoats(vector<int>& pe, int lt) 
    {
        int l=0,r=1e9;
        sort(pe.begin(),pe.end());
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(mid,pe,lt))
            {
               ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};