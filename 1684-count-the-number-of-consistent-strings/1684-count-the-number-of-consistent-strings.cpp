class Solution {
public:
    int countConsistentStrings(string all, vector<string>& words) {
        vector<int> pre(26);
        for(auto x: all){
            pre[x-'a']++;
        }
        int cnt=0;
        for(auto x: words){
            vector<int> fre(26);
            for(auto y: x){
                fre[y-'a']++;
            }
            bool found=true;
            for(int i=0;i<26;i++){
               if(fre[i]>0){
                   if(pre[i]>0)
                       continue;
                   else
                       found = false;
               }
            }
            cnt+=found;
        }
        return cnt;
    }
};