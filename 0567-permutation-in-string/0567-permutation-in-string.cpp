class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> fre(26);
        for(auto x: s1)
            fre[x-'a']+=1;
        vector<int> tmp(26);
        int i=0,j=0,n=s2.size(),m=s1.size();
        while(j<n){
            tmp[s2[j]-'a']+=1;
            if(j-i+1<m)
                j++;
            else if(j-i+1==m){
                if(tmp==fre)
                    return 1;
                tmp[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return 0;
    }
};