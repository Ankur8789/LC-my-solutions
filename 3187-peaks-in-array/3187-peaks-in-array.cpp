class Solution {
public:
    vector<int> segtree;
    void update(int index,int l,int r,int i,int val)
    {
        if(i>r || i<l)
            return ;
        if(l==r)
        {
            segtree[index]=val;
            return;
        }
        int mid=(l+r)/2;
        update(2*index,l,mid,i,val);
        update(2*index+1,mid+1,r,i,val);
        segtree[index]=segtree[2*index]+segtree[2*index+1];
    }
    int query(int index,int l,int r,int li,int ri)
    {
        if(l>ri || r<li)
            return 0;
        if(l>=li && r<=ri)
            return segtree[index];
        int mid=(l+r)/2;
        return query(2*index,l,mid,li,ri)+query(2*index+1,mid+1,r,li,ri);
    }
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) 
    {
       segtree.resize(4*100005);
       int n=nums.size();
       for(int i=0;i<n;i++)
       {
           int peak=0;
           if(i-1>=0 && nums[i]>nums[i-1] && i+1<n && nums[i]>nums[i+1])
               peak=1;
           update(1,0,n-1,i,peak);
       }
       vector<int> ans;
       for(auto x: queries)
       {
           int type=x[0];
           if(type==1)
           {
              int val=query(1,0,n-1,x[1],x[2]);
              val-=query(1,0,n-1,x[1],x[1]);
              if(x[1]!=x[2])
              val-=query(1,0,n-1,x[2],x[2]);
              ans.push_back(val);
           }
           else
           {
              int idx=x[1];
              int val=x[2];
              nums[idx]=val;
              int peak=0;
              if(idx-1>=0 && nums[idx]>nums[idx-1] && idx+1<n && nums[idx]>nums[idx+1])
               peak=1;
              update(1,0,n-1,idx,peak);
              peak=0;
              if(idx-1>=0 && idx-2>=0 && nums[idx-1]>nums[idx-2] && nums[idx-1]>nums[idx])
                  peak=1;
              if(idx-1>=0)
              update(1,0,n-1,idx-1,peak);
              peak=0;
              if(idx+1<n && idx+2<n && nums[idx+1]>nums[idx] && nums[idx+1]>nums[idx+2])
                  peak=1;
              if(idx+1<n)
              update(1,0,n-1,idx+1,peak);
              
           }
       }
       return ans;
    }
};