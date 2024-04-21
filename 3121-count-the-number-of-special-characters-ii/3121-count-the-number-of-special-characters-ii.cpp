class Solution {
public:
    int numberOfSpecialChars(string word) 
    {
       int ans = 0 ; 
       for(char ch = 'a'; ch <='z'; ch++)
       {
           int last = -1 , fst = -1;
           bool ok = true;
           int cnt = 0;
           for(int i = 0; i< word.size(); i++)
           {
               if(ch == word[i])
                   last = i,cnt++;
               if(word[i] == char(ch-32))
               { 
                   if(fst == -1)
                       fst = i;
                   cnt++;
               }
               if(last > fst && last != -1 && fst != -1)
               {
                   ok = false;
                   break ; 
               }
           }
           if(ok && last != -1 && fst != -1)
               ans += 1;
       }
        return ans;
    }
};