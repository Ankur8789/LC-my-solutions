class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<long long,int> mp;
        for(auto x: arr)
            mp[x]+=1;
        for(auto x: mp){
            if(x.first==0){
                if(x.second>1)
                    return 1;
            }
            else{
                int val=x.first;
                if(mp.count(2*val))
                    return 1;
            }
        }
        return 0;
    }
};