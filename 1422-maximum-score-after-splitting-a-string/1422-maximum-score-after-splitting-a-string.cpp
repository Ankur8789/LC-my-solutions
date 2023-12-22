class Solution {
public:
    int maxScore(string s)
    {
       int tot=0;
       for(auto t: s)
           tot+=(t=='1');
       int zr=0;
       int maxi=0;
       for(int i=0;i<s.size()-1;i++)
       {
          if(s[i]=='0')
              zr++;
          else
              tot--;
          maxi=max(maxi,zr+tot);
       }
      return maxi;
    }
};