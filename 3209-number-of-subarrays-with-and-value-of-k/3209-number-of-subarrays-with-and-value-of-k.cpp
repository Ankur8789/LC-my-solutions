class Solution {
public:
    typedef long long ll;
    vector<ll> segtree;
    void update(ll index,ll l,ll r,ll i,ll x)
    {
       if(i>r || i<l)
           return ;
        if(l==r)
        {
            segtree[index]=x;
            return;
        }
        ll mid=(l+r)/2;
        update(2*index,l,mid,i,x);
        update(2*index+1,mid+1,r,i,x);
        segtree[index]=(segtree[2*index]&segtree[2*index+1]);
    }
    int query(ll index,ll l,ll r,ll li,ll ri)
    {
       if(r<li || l>ri)
         return ((1<<30)-1);
       if(l>=li && r<=ri)
           return segtree[index];
        ll mid=(l+r)/2;
        return (query(2*index,l,mid,li,ri) & query(2*index+1,mid+1,r,li,ri));
    }
    long long countSubarrays(vector<int>& nums, int k) 
    {
        segtree.resize(4*100005);
        for(ll i=0;i<nums.size();i++)
            update(1LL,0LL,(nums.size()-1)*1LL,i,nums[i]);
        ll n=nums.size();
        ll ans=0;
        for(ll i=0;i<n;i++)
        {
            ll l=i,r=n-1;
            ll le=-1,ri=-1;
            while(l<=r)
            {
                ll mid=(l+r)/2;
                ll val=query(1,0,n-1,i,mid);
                if(val==k)
                {
                    le=mid;
                    r=mid-1;
                }
                else if(val>k)
                    l=mid+1;
                else
                    r=mid-1;
            }
            l=i,r=n-1;
            while(l<=r)
            {
                ll mid=(l+r)/2;
                ll val=query(1,0,n-1,i,mid);
                if(val==k)
                {
                    ri=mid;
                    l=mid+1;
                }
                else if(val>k)
                    l=mid+1;
                else
                    r=mid-1;
            }
            if(le!=-1)
                ans+=(ri-le+1);
        }
        return ans;
    }
};