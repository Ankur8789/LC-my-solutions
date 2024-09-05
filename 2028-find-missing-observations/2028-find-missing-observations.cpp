class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
      vector<int> ans(n,6);
      int currsum =6*n;
      int m=rolls.size();
      for(auto x: rolls)
        currsum+=x;
      if(currsum%(n+m)==0 && currsum/(n+m)==mean)
          return ans;
      bool ok=false;
      for(int i=0;i<5;i++){
          for(auto&x: ans){
              x--;
              currsum--;
              if(currsum%(n+m)==0 && currsum/(n+m)==mean){
                  ok=true;
                  break;
              }
          }
          if(ok)
              break;
      }
      if(ok)
          return ans;
      else
          return {};
    }
};