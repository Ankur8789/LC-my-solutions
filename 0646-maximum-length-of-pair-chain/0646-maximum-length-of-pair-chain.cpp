class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b)
    {

        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        sort(pairs.begin(),pairs.end(),cmp);
        int res=1;
        int cnt=1;
        int curr=pairs[0][1];
        for(int i=1;i<pairs.size();i++)
        {
            if(curr<pairs[i][0])
            {
               cnt++;
               curr=max(curr,pairs[i][1]);
            }
            
        }
        if(cnt>1)
            res=max(res,cnt);
        return res;
    }
};