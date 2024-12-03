class Solution {
public:
    string addSpaces(string s, vector<int>& sp) {
        string ans="";
        int j=0;
        for(int i=0;i<s.size();i++){
            if(j<sp.size() && i==sp[j]){
                ans+=' ';
                j++;
            }
            ans+=s[i];
        }
        return ans;
    }
};