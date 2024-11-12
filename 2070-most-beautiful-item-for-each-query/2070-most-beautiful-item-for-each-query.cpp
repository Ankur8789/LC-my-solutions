class Solution {
public:
    vector<int> seg;
    void upd(int index,int l,int r,int i,int x){
        if(i<l || i>r)
            return;
        if(l==r){
            seg[index]=x;
            return;
        }
        int mid=(l+r)/2;
        upd(2*index,l,mid,i,x);
        upd(2*index+1,mid+1,r,i,x);
        seg[index]=max(seg[2*index],seg[2*index+1]);        
    }
    int qry(int index,int l,int r,int le,int ri){
        if(r<le || l>ri)
            return -1;
        if(l>=le && r<=ri)
            return seg[index];
        int mid=(l+r)/2;
        return max(qry(2*index,l,mid,le,ri),qry(2*index+1,mid+1,r,le,ri));
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        seg.resize(400020);
        sort(items.begin(),items.end());
        for(int i=0;i<items.size();i++){
            upd(1,0,items.size()-1,i,items[i][1]);
        }
        vector<int> ans;
        for(auto x: queries){
            int l=0,r=items.size()-1,res=-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(items[mid][0]<=x){
                    res=mid;
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            if(res==-1)
                ans.push_back(0);
            else
                ans.push_back(qry(1,0,items.size()-1,0,res));
        }
        return ans;
    }
};