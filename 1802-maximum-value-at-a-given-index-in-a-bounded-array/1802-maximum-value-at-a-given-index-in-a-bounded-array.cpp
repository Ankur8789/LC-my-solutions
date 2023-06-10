class Solution {
public:
    typedef long long ll;
    bool check(ll mid,int index,int maxSum,int n)
    {
        ll sm=0;
        ll left= index;
        ll right=n-index-1;
        ll lsm=0,rsm=0;
        if(left>mid-1)
            lsm+=(mid-1)*mid - (mid*(mid-1))/2 + (left-mid+1);
        else
            lsm+=(left)*mid - (left*(left + 1))/2;
        if(right>mid-1)
            rsm+=(mid-1)*mid - (mid*(mid-1))/2 + (right - mid + 1);
        else
            rsm+=(right)*mid - (right* (right +1 ))/2;
        cout<<lsm<<" "<<rsm<<endl;
        sm=lsm+rsm+mid;
        cout<<sm<<endl;
        return sm<=maxSum;
        //3 4 3 2 1 1
    }
    int maxValue(int n, int index, int maxSum) 
    {
        ll l=1,r=1e9;
        ll ans=-1;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(check(mid,index,maxSum,n))
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        // cout<<check(3,index,maxSum,n)<<endl;
        return ans;
    }
};