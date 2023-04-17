class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& cd, int ec)
    {
      vector<bool> ans;
      int mx=*max_element(begin(cd),end(cd));
       for(auto t: cd)
       {
           if(t+ec>=mx)
               ans.push_back(true);
           else
               ans.push_back(false);
       }
        return ans;
    }
};