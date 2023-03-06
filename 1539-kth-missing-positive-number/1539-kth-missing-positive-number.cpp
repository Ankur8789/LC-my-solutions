class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int vis[10001]={0};
        for(auto t:arr)
            vis[t]+=1;
        int ks=0;
        for(int i=1;i<10001;i++)
        {
            if(vis[i]==0)
                ks++;
            if(ks==k)
                return i;
        }
        return 0;
    }
};