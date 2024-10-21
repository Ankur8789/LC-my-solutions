class Solution {
public:
    int ans = 0;
    int max(int a ,int b){
        if(a < b)
            return b;
        return a;
    }
    void f(int i,string& s,map<string,int>& mp){
        if(i == s.size()){
            ans = max(ans , mp.size());
            return;
        }
        string tem = "";
        for(int j=i;j<s.size();j++){
            tem += s[j];
            mp[tem] += 1;
            f(j+1,s,mp);
            mp[tem] -= 1;
            if(mp[tem] == 0)
                mp.erase(tem);
        }
    }
    int maxUniqueSplit(string s) {
        map<string,int> mp;
        f(0,s,mp);
        return ans;
    }
};