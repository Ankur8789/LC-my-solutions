class Solution {
public:
    vector<string> f(string& s){
        vector<string> res;
        int i=0;
        string temp="";
        while(i<s.size()){
            while(i<s.size() && s[i]!=' ')
                temp+=s[i++];
            res.push_back(temp);
            temp="";
            i++;
        }
        return res;
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int> mp;
        vector<string> x=f(s1);
        vector<string> y=f(s2);
        for(auto t: x)
            mp[t]+=1;
        for(auto t: y)
            mp[t]+=1;
        vector<string> ans;
        for(auto x: mp){
            if(x.second==1)
                ans.push_back(x.first);
        }
        return ans;
        
    }
};