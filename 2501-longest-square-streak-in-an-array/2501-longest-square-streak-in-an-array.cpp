class Solution {
public:
    //another questions on set...socho aisa acha hota hai
    typedef long long ll;
    int longestSquareStreak(vector<int>& nums) 
    {
       multiset<ll> ms;
        for(int i=0;i<nums.size();i++)
            ms.insert(nums[i]);
        ll res=-1;
        for(int i=0;i<nums.size();i++)
        {
            ll v=nums[i];
            ll cc=0;
            while(1)
            {
                if(ms.find(v*v)==ms.end())
                    break;
                cc++;
                v*=v;
            }
          if(cc>0)
              res=max(res,cc+1);
        }
        return res;
    }
};