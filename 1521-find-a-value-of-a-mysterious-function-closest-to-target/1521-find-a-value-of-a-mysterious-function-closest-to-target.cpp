class Solution {
public:
    vector<int> segtree;
    void update(int l,int r,int index,int i,int x)
    {
        if(i>r || i<l)
            return;
        if(l==r)
        {
            segtree[index]=x;
            // cout<<index<<" "<<segtree[index]<<endl;
            return;
        }
        int mid=(l+r)/2;
        update(l,mid,2*index,i,x);
        update(mid+1,r,2*index+1,i,x);
        segtree[index]=(segtree[2*index]&segtree[2*index+1]);
    }
    int query(int l,int r,int index,int li,int ri)
    {
        if(r<li || l>ri)
            return ((1<<24)-1);
        if(l>=li && r<=ri)
            return segtree[index];
        int mid=(l+r)/2;
        return (query(l,mid,2*index,li,ri)&query(mid+1,r,2*index+1,li,ri));
    }
    int closestToTarget(vector<int>& arr, int target) 
    {
        int sz=1;
        int n=arr.size();
        while(sz<n)sz*=2;
        segtree.resize(4*100005);
        for(int i=0;i<n;i++)
            update(0,n-1,1,i,arr[i]);
        int ans=1e9;
        for(int i=0;i<n;i++)
        {
            // just chota ya barabar
            int l=i,r=n-1;
            int res=-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                int val=query(0,n-1,1,i,mid);
                if(val==target)
                    return 0;
                if(val<target)
                {
                    ans=min(ans,abs(val-target));
                    r=mid-1;
                }
                else
                    l=mid+1;
            }
            // just bada ya barabar
            l=i,r=n-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                int val=query(0,n-1,1,i,mid);
                if(val==target)
                    return 0;
                if(val>target)
                {
                    ans=min(ans,abs(val-target));
                    l=mid+1;
                }
                else
                   r=mid-1;
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i;j<n;j++)
        //         cout<<query(0,n-1,1,i,j)<<" ";
        //     cout<<endl;
        // }
        return ans;
    }
};