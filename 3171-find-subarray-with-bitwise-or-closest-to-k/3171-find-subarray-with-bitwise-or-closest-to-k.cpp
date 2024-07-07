class Solution {
public:
    vector<int> segtree;
    void update(int index,int l,int r,int i,int x)
    {
       if(i>r || i<l)
           return ;
        if(l==r)
        {
            segtree[index]=x;
            return;
        }
        int mid=(l+r)/2;
        update(2*index,l,mid,i,x);
        update(2*index+1,mid+1,r,i,x);
        segtree[index]=(segtree[2*index]|segtree[2*index+1]);
    }
    int query(int index,int l,int r,int li,int ri)
    {
       if(r<li || l>ri)
         return 0;
       if(l>=li && r<=ri)
           return segtree[index];
        int mid=(l+r)/2;
        return (query(2*index,l,mid,li,ri) | query(2*index+1,mid+1,r,li,ri));
    }
    int minimumDifference(vector<int>& nums, int k) 
    {
        segtree.resize(4*100005);
        int diff=1e9;
        int ans=-1;
        int n=nums.size();
        for(int i=0;i<n;i++)
            update(1,0,n-1,i,nums[i]);
        for(int i=0;i<n;i++)
        {
            int l=i,r=n-1;
            int res=-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                int val=query(1,0,n-1,i,mid);
                if(val==k)
                    return 0;
                if(val>k)
                {
                    int nd=abs(val-k);
                    // cout<<nd<<endl;
                    if(diff>nd)
                        diff=nd;
                    r=mid-1;
                }
                else
                    l=mid+1;
            }
            l=i,r=n-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                int val=query(1,0,n-1,i,mid);
                if(val==k)
                    return 0;
                if(val<k)
                {
                    int nd=abs(val-k);
                    // cout<<nd<<endl;
                    if(nd<diff)
                        diff=nd;
                    l=mid+1;
                }
                else
                    r=mid-1;
            }
        }
        return diff;
    }
};