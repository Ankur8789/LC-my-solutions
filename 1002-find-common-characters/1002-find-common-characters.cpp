class Solution {
public:
    vector<string> commonChars(vector<string>& words) 
    {
        int n = words.size();
        vector<int> finalFreq(26,INT_MAX);
        vector<string>ans;
        for(int i=0; i<n; i++)
        {
            vector<int> currFreq(26,0);
            for(char c : words[i])
            {
                currFreq[c-'a']++;
            }
            for(char c='a'; c<='z'; c++)
            {
                finalFreq[c-'a'] = min(finalFreq[c-'a'], currFreq[c-'a']);
            }
        }
        for(char c = 'a'; c<= 'z'; c++)
        {
            while(finalFreq[c-'a']--)
            {
                ans.push_back(string(1,c));
            }
        }
        return ans;
    }
};