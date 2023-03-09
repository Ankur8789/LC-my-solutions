class Solution {
public:
    map<pair<int,vector<int>>,int> dp;
    int f(int i,vector<int>& freq,vector<string>& words,vector<int>& score)
    {
        if(i==words.size())
            return 0;
        if(dp.find({i,freq})!=dp.end())
            return dp[{i,freq}];
         vector<int> fx=freq;
        int flag=true;
        string str=words[i];
        int sm=0;
        int ans=-1e5;
        for(int idx=0;idx<str.size();idx++)
        {
            if(fx[str[idx]-'a']==0)
            {
                flag=false;
                break;
            }
            else
            {
                fx[str[idx]-'a']--;
                sm+=score[str[idx]-'a'];
            }
        }
        if(flag==true)
        ans=max(ans,sm+f(i+1,fx,words,score));
        ans=max(ans,f(i+1,freq,words,score));
        return dp[{i,freq}]=ans;
            
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) 
    {   
        vector<int> fre(26);
        for(auto t:letters)
            fre[t-'a']++;
        auto ans=f(0,fre,words,score);
        return ans;
    }
};