class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int> mp;
        for(auto x: arr)
            mp[x]+=1;
        vector<string> res;
        for(auto x: arr){
            if(mp[x]==1){
                res.push_back(x);
            }
        }
        if(res.size()<k)
            return "";
        else
            return res[k-1];
        
    }
};