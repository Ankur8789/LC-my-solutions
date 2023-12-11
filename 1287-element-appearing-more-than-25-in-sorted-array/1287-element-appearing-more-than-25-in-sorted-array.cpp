class Solution {
public:
    int findSpecialInteger(vector<int>& arr) 
    {
       map<int,int> mp;
       for(auto t: arr)mp[t]++;
       int n=arr.size();
        n/=4;
       for(auto t: mp)
       {
           if(t.second>n)return t.first;
       }
        return -1;
    }
};