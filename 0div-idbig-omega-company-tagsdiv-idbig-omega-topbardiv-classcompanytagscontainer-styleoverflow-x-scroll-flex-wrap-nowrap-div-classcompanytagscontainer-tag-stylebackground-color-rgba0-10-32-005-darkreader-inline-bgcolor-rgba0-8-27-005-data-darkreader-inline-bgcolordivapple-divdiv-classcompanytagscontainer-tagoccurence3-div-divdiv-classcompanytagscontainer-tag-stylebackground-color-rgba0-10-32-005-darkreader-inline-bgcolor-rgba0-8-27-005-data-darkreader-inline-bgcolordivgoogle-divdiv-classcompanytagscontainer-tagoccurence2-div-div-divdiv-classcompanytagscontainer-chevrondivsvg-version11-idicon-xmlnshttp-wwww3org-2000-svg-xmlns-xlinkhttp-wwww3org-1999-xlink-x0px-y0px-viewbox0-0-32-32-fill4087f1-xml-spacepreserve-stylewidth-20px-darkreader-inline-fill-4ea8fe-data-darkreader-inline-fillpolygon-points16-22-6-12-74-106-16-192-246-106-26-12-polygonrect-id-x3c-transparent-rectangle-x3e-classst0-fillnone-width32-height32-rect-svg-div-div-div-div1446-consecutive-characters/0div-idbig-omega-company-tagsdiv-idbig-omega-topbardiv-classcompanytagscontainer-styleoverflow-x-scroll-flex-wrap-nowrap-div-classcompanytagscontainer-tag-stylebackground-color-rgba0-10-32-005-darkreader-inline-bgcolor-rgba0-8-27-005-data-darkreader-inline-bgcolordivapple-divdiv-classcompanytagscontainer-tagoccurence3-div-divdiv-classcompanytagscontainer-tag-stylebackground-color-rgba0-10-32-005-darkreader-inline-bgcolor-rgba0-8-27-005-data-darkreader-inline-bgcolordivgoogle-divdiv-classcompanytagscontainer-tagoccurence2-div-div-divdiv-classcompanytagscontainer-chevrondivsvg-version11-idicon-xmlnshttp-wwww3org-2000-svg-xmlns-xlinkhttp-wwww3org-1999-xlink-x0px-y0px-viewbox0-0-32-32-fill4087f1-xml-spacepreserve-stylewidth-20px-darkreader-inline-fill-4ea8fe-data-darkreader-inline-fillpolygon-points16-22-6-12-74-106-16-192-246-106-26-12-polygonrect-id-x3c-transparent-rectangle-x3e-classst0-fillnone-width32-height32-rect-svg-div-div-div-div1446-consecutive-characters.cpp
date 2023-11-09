class Solution {
public:
    int maxPower(string s) 
    {
        int ans=1;
        for(char ch='a';ch<='z';ch++)
        {
            int cnt=0;
            for(auto t: s)
            {
                if(t==ch)
                {
                    cnt++;
                    ans=max(ans,cnt);
                }
                else
                    cnt=0;
            }
        }
        return ans;
    }
};