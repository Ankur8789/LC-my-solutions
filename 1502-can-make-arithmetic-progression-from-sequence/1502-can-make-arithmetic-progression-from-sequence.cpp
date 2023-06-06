class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        map<int,int> mp;
        for(int i=0;i<arr.size()-1;i++)
            mp[arr[i]-arr[i+1]]++;
        return mp.size()==1;
        
    }
};