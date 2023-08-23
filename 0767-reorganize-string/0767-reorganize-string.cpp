class Solution {
public:
    string reorganizeString(string s) 
    {
        vector<int> freq(26, 0);
        int mx = 0, letter = 0, idx = 0;
        for(auto ch : s)
        {
            freq[ch-'a']++;
            if(mx < freq[ch-'a']) 
            {
                mx = freq[ch-'a'];
                letter = ch-'a';
            }
        }
        if (mx > (s.length()+1)/2) 
            return "";
        string ans = s;
        while(freq[letter]) 
        {
            ans[idx] = 'a'+letter;
            idx += 2;
            freq[letter]--;
        }

        for(int i=0;i<26;i++)
        {
            while(freq[i] > 0) 
            {
                if(idx >= s.size()) idx = 1;
                ans[idx] = 'a' + i;
                idx += 2;
                freq[i]--;
            }
        }
        return ans;
    }
};