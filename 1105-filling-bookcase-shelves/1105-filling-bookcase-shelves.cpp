class Solution {
public:
    int dp[1001];
    int f(int i,vector<vector<int>>& books, int sw)
    {
        if(i==books.size())
            return 0;
        auto&x=dp[i];
        if(x!=-1)
            return x;
        int width=sw;
        int ans=1e9;
        int ht=books[i][1];
        int idx=i;
        for(idx=i;idx<books.size();idx++)
        {
            if(books[idx][0]>width)
                break;
            width-=books[idx][0];
            ht=max(ht,books[idx][1]);
            ans=min(ans,ht+f(idx+1,books,sw));
        }
        ans=min(ans,ht+f(idx,books,sw));
        return x=ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int sw) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=f(0,books,sw);
        return ans;
    }
};