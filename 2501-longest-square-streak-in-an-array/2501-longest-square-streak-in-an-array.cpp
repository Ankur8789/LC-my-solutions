class Solution {
public:
    typedef long long ll;
    int longestSquareStreak(vector<int>& nums) {
       multiset<int> ms;
       for(auto x : nums){
           ms.insert(x);
       }
       int ans = 0;
       for(auto x : ms){
           ll val = x;
           int cnt = 1;
           while(1){
               if(val * val > 100000)
                   break;
               if(ms.count(val * val)){
                   cnt += 1;
                   val *= val;
               }
               else{
                   break;
               }
           }
           ans = max(ans , cnt);
       }
        if(ans == 1)
            ans *= -1;
        return ans;
    }
};