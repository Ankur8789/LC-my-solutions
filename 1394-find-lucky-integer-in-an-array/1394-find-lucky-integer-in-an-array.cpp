class Solution {
public:
    int findLucky(vector<int>& arr) 
    {
       map<int,int> mp;
       for(auto x: arr)mp[x]+=1;
       for(auto it=mp.crbegin();it!=mp.crend();++it)
       {
           if(it->first==it->second)
               return it->second;
       }
       return -1;
    }
};