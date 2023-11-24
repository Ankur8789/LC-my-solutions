class Solution {
public:
    int maxCoins(vector<int>& piles) 
    {
        // 2 4 1 2 7 8
        // 1 2 2 4 7 8
       sort(piles.begin(),piles.end());
       int cnt=0;
       int n=piles.size();
       int i=0,j=n-2;
       while(j>i)
       {
           cnt+=piles[j];
           i++;
           j-=2;
       }
       return cnt;
       
    }
};