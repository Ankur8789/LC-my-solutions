class Solution {
public:
    vector<int> sortJumbled(vector<int>& m, vector<int>& nums)
    {
       map<int,int> mp;
       for(int i=0;i<m.size();i++)
           mp[i]=m[i];
       vector<vector<int>> vp;
       int cnt=0;
       for(auto x: nums)
       {
           string s=std::to_string(x);
           string ns="";
           for(auto y: s)
               ns+=char(mp[y-'0']+'0');
           int val=stoi(ns);
           vp.push_back({val,cnt,x});
           cnt++;
           // cout<<val<<" ";
       }
       sort(begin(vp),end(vp));
       vector<int> ans;
       for(auto x: vp)
           ans.push_back(x[2]);
       return ans;
    }
};