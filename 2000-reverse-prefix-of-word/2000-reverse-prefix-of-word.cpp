class Solution {
public:
    string reversePrefix(string word, char ch) 
    {
         string str = "";
         for(int i = 0;i < word.size(); i++)
         {
             str += word[i];
             if(word[i] == ch)
             {
                 reverse(begin(str),end(str));
                 string ans = "";
                 ans += str;
                 if(i < word.size() - 1)
                     ans += word.substr(i+1);
                 return ans;
             }
         }
        return str;
    }
};