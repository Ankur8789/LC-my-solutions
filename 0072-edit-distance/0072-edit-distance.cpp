class Solution {
public:
    int dp[501][501];
    int f(int i,int j,string& word1, string& word2)
    {
        if(i==word1.size())
            return word2.size()-j;
        if(j==word2.size())
            return word1.size()-i;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(word1[i]==word2[j])
            return dp[i][j]=f(i+1,j+1,word1,word2);
        else
        return dp[i][j]=1+min({f(i+1,j+1,word1,word2),f(i+1,j,word1,word2),f(i,j+1,word1,word2)});
    }
    int minDistance(string word1, string word2) 
    {   memset(dp,-1,sizeof(dp));
        int ans=f(0,0,word1,word2);
        return ans;
    }
};