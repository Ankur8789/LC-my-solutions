class Solution {
public:
    int minAnagramLength(string s) 
    {
       vector<int> factors;
       int n = s.size();
       for(int i=1;i*i<=n;i++)
       {
           if(n%i == 0)
           {
              factors.push_back(i);
              if(n/i == i)
                  continue;
               factors.push_back(n/i);
           }
       }
       sort(begin(factors), end(factors));
       for(auto x : factors)
       {
           vector<int> start(26);
           for(int i = 0;i < x;i++)
               start[s[i]-'a']++;
           int cnt = 0;
           for(int i = x ; i < n;i += x)
           {
               vector<int> fre(26);
               for(int j = i;j < i+x ; j++)
                   fre[s[j]-'a']++;
               if(start == fre)
                   cnt++;
           }
           int rev = n / x;
           rev -= 1;
           if(rev == cnt)
               return x;
           
       }
        return n;
        
        
    }
};